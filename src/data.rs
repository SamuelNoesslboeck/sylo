// ####################
// #    DATA-TYPES    #
// ####################
    /// Direction of movement
    #[derive(Clone, Copy, PartialEq, PartialOrd, Eq, Debug, Default)]
    #[cfg_attr(feature = "serde", derive(serde::Serialize, serde::Deserialize))]
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

    impl Into<embedded_hal::Direction> for Direction {
        fn into(self) -> embedded_hal::Direction {
            match self {
                Self::CCW => embedded_hal::Direction::Downcounting,
                Self::CW => embedded_hal::Direction::Upcounting
            }
        }
    }

    impl From<embedded_hal::Direction> for Direction {
        fn from(value: embedded_hal::Direction) -> Self {
            match value {
                embedded_hal::Direction::Downcounting => Self::CCW,
                embedded_hal::Direction::Upcounting => Self::CW
            }
        }
    }
// 
