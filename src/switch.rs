use embedded_hal::digital::v2::{InputPin, OutputPin};

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

    pub fn is_triggered(&mut self) -> Result<bool, P::Error> {
        Ok(self.pin.is_high()? == self.trigger)
    }
}

impl<P : InputPin> BoolMeas for Switch<P> {
    type Error = P::Error;

    fn meas(&mut self) -> Result<bool, Self::Error> {
        self.is_triggered()
    }
}

/// A simple relay structure
pub struct Relay<P : OutputPin> {
    pin : P
}

impl<P : OutputPin> Relay<P> {
    /// Creates a new relay
    pub fn new(pin : P) -> Self {
        Self {
            pin
        }
    }

    /// Sets the relay to high
    pub fn set_high(&mut self) -> Result<(), P::Error> {
        self.pin.set_high()
    }

    /// Sets the relay to low
    pub fn set_low(&mut self) -> Result<(), P::Error> {
        self.pin.set_low()
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