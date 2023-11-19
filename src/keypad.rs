use embedded_hal::digital::v2::{OutputPin, InputPin};

pub const SIMPLE_TABLE : [[char; 4]; 4] = [
    [ '1', '2', '3', 'A' ],
    [ '4', '5', '6', 'B' ],
    [ '7', '8', '9', 'C' ],
    [ '*', '0', '#', 'D' ]
];

pub const BUFFER_LEN : usize = 16;

pub struct KeyPad<'a, E> {
    // Pins
    rows : [&'a mut dyn OutputPin<Error = E>; 4],
    columns : [&'a dyn InputPin<Error = E>; 4],
    // Data
    table : [[char; 4]; 4],     // [ Row [ Column ] ]
    buffer : [char; BUFFER_LEN],
    length : usize,
    last_char : char
}

impl<'a, E> KeyPad<'a, E> {
    pub fn new(mut rows : [&'a mut dyn OutputPin<Error = E>; 4], columns: [&'a dyn InputPin<Error = E>; 4], table : [[char; 4]; 4]) -> Result<Self, E> {
        for row in &mut rows {
            row.set_high()?;
        }

        Ok(Self {
            rows,
            columns,
            table,

            buffer: ['\0'; 16],
            length: 0,
            last_char: '\0'
        })
    }

    pub fn input(&self) -> (&[char], usize) {
        ( &self.buffer, self.length )
    }

    pub fn clear_input(&mut self) {
        self.length = 0;
    }

    fn fire(&mut self, row : usize, column : usize) -> Option<char> {
        if self.length >= BUFFER_LEN {
            return None;     // Quit if buffer is full
        }

        let c = self.table[row][column];

        self.buffer[self.length] = c;
        self.length += 1;
        self.last_char = c;

        Some(c)
    }

    pub fn check_inputs(&mut self) -> Result<Option<char>, E> {
        let mut reset_last = true;

        for r in 0 .. 4 {
            for c in 0 .. 4 {
                let column = &self.columns[c];

                self.rows[r].set_low()?;
                
                if column.is_low()? {
                    if self.table[r][c] == self.last_char {
                        reset_last = false;
                        continue;
                    }

                    let f = self.fire(r, c);

                    if f.is_some() {
                        self.rows[r].set_high()?;

                        return Ok(f);
                    }
                }

                self.rows[r].set_high()?;
            }
        }

        if reset_last {
            self.last_char = '\0';
        }

        Ok(None)
    }
}