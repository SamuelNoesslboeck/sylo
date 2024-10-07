// ################################
// #    TOn - Timing component    #
// ################################
//
// > Version 0.1.0
// >
// > Build for the Arduino framework!

# pragma once

/// @brief A function block class common in PLC programming, used to delay an output signal for a certain amount of time, the `phase`
class TOn {
private:
    /// @brief Timestamp in milliseconds since the input signal has been high
    unsigned long since;
    /// @brief Helper variable to track a constant input signal
    bool waiting;

public:
    /// @brief The phase (in milliseconds) regulates how long the output signal will be delayed from the constant input signal
    unsigned long phase; 

    /// @brief Creates a new instance of a TOn timing component
    /// @param phase The phase (in milliseconds) regulates how long the output signal will be delayed from the constant input signal
    TOn(unsigned long phase) : since(0), phase(phase), waiting(false) {
        // No further construction needed
    }

    /// @brief Executes the block, updating all internal variables and returning the output signal
    /// @param in The input signal of the block
    /// @return The output signal of the block
    bool exec(bool in) {
        if (in) {
            if (!this->waiting) {
                this->waiting = true;
                this->since = millis();
            } 

            if ((millis() - this->since) > phase) {
                return true;
            }
        } else {
            this->waiting = false;
        }

        return false;
    }

    /// @brief Returns the time (in milliseconds) that the component got a constant `HIGH` input signal
    unsigned long elapsed_time() {
        if (this->waiting) {
            return (millis() - this->since);
        } else {
            return false;
        }
    }
}; 