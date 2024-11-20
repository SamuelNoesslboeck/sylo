// ########################
// #    ROTARY-ENCODER    #
// ########################
// >
// > Build for the Arduino framework!

# pragma once

# include <Arduino.h>

/// @brief A movement of the rotary encoder
enum RotaryMove {
    /// @brief No movement has taken place
    None,
    /// @brief The encoder has moved in the clockwise direction
    CW,
    /// @brief The encoder has moved in the counter clockwise direction
    CCW
};

static bool is_movement(RotaryMove move) {
    return (bool)move;
}

/// @brief A general structure for rotary encoders
struct RotaryEncoder {
private:
    // Stores the last state of the encoder
    bool clk_last, dt_last;

public:
    /// @brief The switch pin of the rotary encoder
    uint8_t sw;
    /// @brief The clock pin of the rotary encoder
    uint8_t clk;
    /// @brief The data pin of the rotary encoder
    uint8_t dt;
    /// @brief A counter value for the total distance moved
    int32_t counter;

    /// @brief Create a new rotary encoder
    /// @param sw The switch pin of the rotary encoder
    /// @param dt The data pin of the rotary encoder
    /// @param clk The clock pin of the rotary encoder
    RotaryEncoder(uint8_t sw, uint8_t dt, uint8_t clk) 
        : counter(0), clk_last(false), dt_last(false), sw(sw), clk(clk), dt(dt)
    {
        // Setup all the required pins
        pinMode(sw, INPUT);
        pinMode(clk, INPUT);
        pinMode(dt, INPUT);
    }

    // Checking functions

        /// @brief Check the current state of the rotary switch
        /// @return The switch value
        bool check_switch() {
            // Switch is normally open!
            return digitalRead(this->sw) == LOW;
        }

        /// @brief Check if a movement has occured in the rotary encoder
        /// @return The movement that happened
        RotaryMove check_rotary() {
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

    // Other functions

        /// @brief Resets the internal counter of the rotary encoder class
        void reset_counter() {
            this->counter = 0;
        }
    //
};