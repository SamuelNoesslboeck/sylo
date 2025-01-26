// ##################################
// #    PULSAR - Timer Component    #
// ##################################
//
// > Version: 0.1.0
// > 
// > Build for the Arduino framework!

# pragma once

# include <Arduino.h>

class Pulsar {
public: 
    unsigned int phase;

    Pulsar(unsigned int phase) : phase(phase) {
        // No further instructions required
    }

    bool exec() {
        // Explaination:
        // - `millis() >> 1` is the same as `millis() * 2`
        // - Then dividing by the `phase`, this returns the total amount of *half phases* since the microcontorller start-up
        // - Then taking the modulo of 2 returns `TRUE` for odd number of half phases, `FALSE` for even number of half phases
        //
        // Very efficient code for returning a pulsing signal with the given pulse time `phase`
        return (bool)(((millis() >> 1) / this->phase) % 2);
    }
}; 