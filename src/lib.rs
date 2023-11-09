//! # sylo
//! 
//! A library for basic devices, sensors and more with `embedded-hal` implementations 
#![no_std]
#![warn(missing_docs)]

// ####################
// #    SUBMODULES    #
// ####################
    mod switch;  

    pub use switch::*;
//

// ####################
// #    DATA-TYPES    #
// ####################
    /// Direction of movement
    #[derive(Clone, Copy, PartialEq, PartialOrd, Eq, Debug, Default)]
    #[repr(u8)]
    pub enum Direction {
        /// Counterclockwise (`false` / `0`)
        CCW,
        /// Clockwise (`true` / `1`)
        #[default]
        CW
    }

    impl Direction {
        /// Creates a new `Direction` value from a bool
        /// - `true` is `CW`
        /// - `false` is `CCW`
        #[inline]
        pub fn from_bool(b : bool) -> Self {
            if b { Direction::CW } else { Direction::CCW }
        }

        /// Converts the given direction into a bool value for logic signals
        /// - `CW` is `true`
        /// - `CCW` is `false` 
        #[inline]
        pub fn as_bool(self) -> bool {
            match self {
                Direction::CCW => false,
                Direction::CW => true
            }
        }

        /// Parses a new `Direction` value from a `u8`
        /// - `0` is `CCW`
        /// - Everything else is `CW` 
        #[inline]
        pub fn from_u8(u : u8) -> Self {
            if u == 0 { Direction::CCW } else { Direction::CW }
        } 

        /// Converts the given `Direction` into a `u8` value
        #[inline]
        pub fn as_u8(self) -> u8 {
            match self {
                Direction::CCW => 0,
                Direction::CW => 1
            }
        }
    }

    // Conversions
    impl Into<bool> for Direction {
        fn into(self) -> bool {
            self.as_bool()
        }
    }

    impl From<bool> for Direction {
        fn from(value: bool) -> Self {
            Self::from_bool(value)
        }
    }

    impl Into<u8> for Direction {
        fn into(self) -> u8 {
            self.as_u8()
        }
    }

    impl From<u8> for Direction {
        fn from(value: u8) -> Self {
            Self::from_u8(value)
        }
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