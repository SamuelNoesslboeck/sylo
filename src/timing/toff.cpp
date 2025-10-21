# include "sylo/timing/toff.hpp"

# include <Arduino.h>

TOff::TOff(unsigned long phase) : last(0), phase(phase) {
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

unsigned long TOff::elapsed_time() {
    return (millis() - this->last);
}

bool TOff::operator()(bool in) {
    return this->exec(in);
}