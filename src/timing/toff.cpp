# include "sylo/timing/toff.hpp"

# include <Arduino.h>

TOff::TOff(uint32_t phase) : last(0), phase(phase) {
    // No further construction needed
}

bool TOff::exec(bool in) {
    if (in) {
        last = millis();
        return true;
    }

    if (this->elapsed_time() <= phase) {
        return true;
    }

    return false;
}

uint32_t TOff::elapsed_time() {
    return (millis() - this->last);
}

bool TOff::operator()(bool in) {
    return this->exec(in);
}