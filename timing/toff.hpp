// #################################
// #    TOff - Timing component    #
// #################################
//
// > Version 0.1.0
// >
// > Build for the Arduino framework!

# pragma once

# include <Arduino.h>

/// @brief A function block class common in PLC programming, used to keep input signals alive longer for a fixed period of time, the `phase`
class TOff {
private:
    /// @brief Timestamp in milliseconds of the last time the input signal has been `HIGH`
    unsigned long last;

public:
    /// @brief The phase (in milliseconds) regulates how long the output signal should be kept `HIGH`, when the input signal already dropped to `LOW`
    unsigned long phase; 

    /// @brief Creates a new instance of a TOff timing component
    /// @param phase The phase (in milliseconds) regulates how long the output signal should be kept `HIGH`, when the input signal already dropped to `LOW`
    TOff(unsigned long phase) : last(0), phase(phase) {
        // No further construction needed
    }

    /// @brief Executes the block, updating all internal variables and returning the output signal
    /// @param in The input signal of the block
    /// @return The output signal of the block
    bool exec(bool in) {
        if (in) {
            last = millis();
            return true;
        }

        if (this->elapsed_time() <= phase) {
            return true;
        }

        return false;
    }

    /// @brief Returns the elapsed time (in milliseconds) since the last `HIGH` on the input signal
    unsigned long elapsed_time() {
        return (millis() - this->last);
    }
}; 