use crate::Direction;

pub trait Stepped {
    type Error;

    fn step(&mut self) -> Result<(), Self::Error>;

    fn dir(&self) -> Direction;

    fn set_dir(&mut self) -> Result<(), Self::Error>;
}