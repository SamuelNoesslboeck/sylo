use embedded_hal::digital::v2::InputPin;

use crate::BoolMeas;

/// A simple switch that can be negated
pub struct Switch<P : InputPin> {
    pin : P,
    trigger : bool
}

impl<P : InputPin> Switch<P> {
    /// Creates a new switch
    pub fn new(pin : P, trigger : bool) -> Self {
        Self {
            pin, 
            trigger
        }
    }
}

impl<P : InputPin> BoolMeas for Switch<P> {
    type Error = P::Error;

    fn meas(&mut self) -> Result<bool, Self::Error> {
        Ok(self.pin.is_high()? == self.trigger)
    }
}


// pub struct RotaryEncoder<DT : InputPin, CLK : InputPin> {
//     dt : DT,
//     clk : CLK,

//     prev_dt : bool,
//     prev_clk : bool
// }

// impl<DT : InputPin, CLK : InputPin> RotaryEncoder<DT, CLK> {
//     pub fn new(dt : DT, clk : CLK) -> Result<Self,  {
//         Self {
//             dt, 
//             clk,

//             prev_dt: false,
//             prev_clk: false
//         }
//     }

//     pub fn update(&mut self) -> Option<Direction> {
        
//     }
// }