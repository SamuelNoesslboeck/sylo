# include "sylo/components/rotary_encoder.hpp"

# include <Arduino.h>

bool is_movement(RotaryMove move) {
    return (bool)move;
}

RotaryEncoder::RotaryEncoder(uint8_t sw, uint8_t dt, uint8_t clk) 
    : sw(sw), clk(clk), dt(dt)
{
    // Setup all the required pins
    pinMode(sw, INPUT);
    pinMode(clk, INPUT);
    pinMode(dt, INPUT);

    this->set_zero();
}

void RotaryEncoder::set_zero() {
    this->clk_last = digitalRead(this->clk);
    this->dt_last = digitalRead(this->dt);
    this->counter = 0;
}

// Checking functions
    /// @brief Check the current state of the rotary switch
    /// @return The switch value
    bool RotaryEncoder::check_switch() {
        // Switch is normally open!
        return digitalRead(this->sw) == LOW;
    }

    /// @brief Check if a movement has occured in the rotary encoder
    /// @return The movement that happened
    RotaryMove RotaryEncoder::check_rotary() {
        bool clk_new = digitalRead(this->clk);
        bool dt_new = digitalRead(this->dt);

        RotaryMove move = RotaryMove::None;

        if (dt_new != dt_last) {
            if (dt_new ^ clk_new) {
                // Clockwise
                counter++;
                move = RotaryMove::CW;
            } else {
                // Counter-Clockwise
                counter--;
                move = RotaryMove::CCW;
            }
        }

        this->clk_last = clk_new;
        this->dt_last = dt_new;

        return move;
    }
//