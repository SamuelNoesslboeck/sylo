// ##################################
// #    Timer - Timing component    #
// ##################################
// >
// > Build for the Arduino framework!

# pragma once

# include <Arduino.h>

class Timer {
private:
    uint32_t set_stamp = 0;
    uint32_t duration = 0;

public:
    Timer() { }

    void set() {
        this->set_stamp = millis();
    }

    void set(uint32_t duration) {
        this->set_stamp = millis();
        this->duration = duration;
    }

    bool running() {
        return (this->set_stamp + this->duration) > millis();
    }

    bool has_elapsed() {
        return (this->set_stamp + this->duration) < millis();
    }
};