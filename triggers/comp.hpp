// ############################################
// #    Comp - Comparing trigger component    #
// ############################################
// >
// > Build for the Arduino framework!

# pragma once

# include <Arduino.h>

class Comp {
private:
    /// @brief The last value this component has triggered too
    int16_t last_trig_value;
    

public:
    /// @brief The difference in values to trigger a new event
    uint16_t delta_trig;
    /// @brief The difference between the last value `exec` hast been called with and the last value the block has been triggered with
    int16_t delta;

    Comp(uint16_t delta_trig) : delta_trig(delta_trig) { }

    bool exec(int16_t value) {
        this->delta = value - this->last_trig_value;

        if (_abs(value - this->last_trig_value) > this->delta_trig) {
            last_trig_value = value;
            return true; 
        }

        return false;
    }

    bool operator()(int16_t value) {
        return this->exec(value);
    }
};