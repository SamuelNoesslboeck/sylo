use embedded_hal::PwmPin;

use crate::Direction;

/// A simple dc motor with two pins as PWM control
pub struct DcMotor<CW : PwmPin, CCW : PwmPin> 
where
    CW::Duty : Copy + Default,
    CCW::Duty : Copy + Default + From<CW::Duty>
{
    /// Output signal for first pin
    sig_cw : CW,
    /// Output signal for
    sig_ccw : CCW,

    /// Current movement direction
    _dir : Direction,
    /// Speed factor (e.g. PWM-duty-cycle of the component)
    _speed : CW::Duty
}

impl<CW : PwmPin, CCW : PwmPin> DcMotor<CW, CCW> 
where
    CW::Duty : Copy + Default,
    CCW::Duty : Copy + Default + From<CW::Duty>
{
    /// Creates a new instance of a `DcMotor` with the following parameters
    /// - `pin_cw` is the pin for driving the motor in the clockwise direction
    /// - `pin_ccw` is the pin for driving the motor in the counter-clockwise direction
    /// - `freq` defines the PWM-frequency for the output signal
    pub fn new(cw : CW, ccw : CCW) -> Self {
        Self {
            sig_cw: cw,
            sig_ccw: ccw,

            _dir: Direction::default(),
            _speed: CW::Duty::default()
        }
    }

    // Accessors
        /// The current moving direction of the motor
        #[inline(always)]
        pub fn dir(&self) -> Direction {
            self._dir
        }

        /// The current speed of the motor
        #[inline(always)]
        pub fn speed(&self) -> CW::Duty {
            self._speed
        }
    // 

    // Enable & Disable
        /// Enables the motor
        pub fn enable(&mut self) {
            self.sig_cw.enable();
            self.sig_ccw.enable();
        }

        /// Disables the motor
        pub fn disable(&mut self) {
            self.sig_cw.disable();
            self.sig_ccw.disable();
        }
    // 

    /// Drive the motor at a certain duty
    pub fn drive(&mut self, dir : Direction, speed : CW::Duty) {
        self._dir = dir;
        self._speed = speed;

        match self._dir {
            Direction::CW => {
                self.sig_cw.set_duty(speed);
                self.sig_ccw.set_duty(CCW::Duty::default());
            },
            Direction::CCW => {
                self.sig_cw.set_duty(CW::Duty::default());
                self.sig_ccw.set_duty(speed.into());
            },
        }
    }
}