# include "sylo/timing/timer.hpp"

# include <Arduino.h>

Timer::Timer() { }

Timer::Timer(uint32_t duration) {
    this->duration = duration;
}

void Timer::set() {
    this->set_stamp = millis();
}

void Timer::set(uint32_t duration) {
    this->set_stamp = millis();
    this->duration = duration;
}

bool Timer::running() {
    return (this->set_stamp + this->duration) > millis();
}

bool Timer::has_elapsed() {
    return (this->set_stamp + this->duration) < millis();
}