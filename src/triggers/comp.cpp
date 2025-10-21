# include "sylo/triggers/comp.hpp"

# include <inttypes.h>
# include <math.h>

Comp::Comp(uint16_t delta_trig) : delta_trig(delta_trig) { }

bool Comp::exec(int16_t value) {
    this->delta = value - this->last_trig_value;

    if (abs(value - this->last_trig_value) > this->delta_trig) {
        this->last_trig_value = value;
        return true;
    }

    return false;
}

bool Comp::operator()(int16_t value) {
    return this->exec(value);
}