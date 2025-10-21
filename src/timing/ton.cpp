# include "sylo/timing/ton.hpp"

# include <Arduino.h>

/// @brief Creates a new instance of a TOn timing component
/// @param phase The phase (in milliseconds) regulates how long the output signal will be delayed from the constant input signal
TOn::TOn(uint32_t phase) : phase(phase) {
    // No further construction needed
}

/// @brief Executes the block, updating all internal variables and returning the output signal
/// @param in The input signal of the block
/// @return The output signal of the block
bool TOn::exec(bool in) {
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
uint32_t TOn::elapsed_time() {
    if (this->waiting) {
        return (millis() - this->since);
    } else {
        return false;
    }
}

/// @brief Executes the block, updating all internal variables and returning the output signal
/// @param in The input signal of the block
/// @return The output signal of the block
bool TOn::operator()(bool in) {
    return this->exec(in);
}