//! # sylo
//! 
//! A library for basic devices, sensors and more with `embedded-hal` implementations 
#![no_std]
// #![warn(missing_docs)]

// ####################
// #    SUBMODULES    #
// ####################
    mod data;
    pub use data::Direction;

    mod dc_motor;
    pub use dc_motor::DcMotor;

    pub mod keypad;
    pub use keypad::KeyPad;

    mod stepper;
    // pub use stepper;

    mod switch;  
    pub use switch::Switch;
//

// ##########################
// #    ENABLE / DISABLE    #
// ##########################
    /// An universal trait that gives the implemented type an `enable` function
    pub trait Enable {
        /// Enables this instance
        fn enable(&mut self);
    }

    /// An universal trait that gives the implemented type a `disable` function
    pub trait Disable {
        /// Disables this instance
        fn disable(&mut self);
    }
// 

// ######################
// #    MEAS-TRAITS     #
// ######################
    /// A trait that marks the given type as a measurement structure that can measure a value and return a `bool` at any time
    pub trait BoolMeas { 
        /// The error that can occur when taking the measurement
        type Error;

        /// Take a measurement and get a `bool` value
        fn meas(&mut self) -> Result<bool, Self::Error>;
    }

    /// A trait that marks the given type as a measurement structure that can measure a value and return a `i8` at any time
    pub trait ByteMeas { 
        /// The error that can occur when taking the measurement
        type Error;

        /// Take a measurement and get a `i8` value
        fn meas(&mut self) -> Result<i8, Self::Error>;
    }

    /// A trait that marks the given type as a measurement structure that can measure a value and return a `i16` at any time
    pub trait ShortMeas {
        /// The error that can occur when taking the measurement
        type Error;

        /// Take a measurement and get a `i16` value
        fn meas(&mut self) -> Result<i16, Self::Error>;
    }

    /// A trait that marks the given type as a measurement structure that can measure a value and return a `i32` at any time
    pub trait IntMeas {
        /// The error that can occur when taking the measurement
        type Error;

        /// Take a measurement and get a `i32` value
        fn meas(&mut self) -> Result<i32, Self::Error>;
    }   
    
    /// A trait that marks the given type as a measurement structure that can measure a value and return a `f32` at any time
    #[cfg(feature = "floats")]
    pub trait FloatMeas {
        /// The error that can occur when taking the measurement
        type Error;

        /// Take a measurement and get a `f32` value
        fn meas(&mut self) -> Result<f32, Self::Error>;
    }
// 