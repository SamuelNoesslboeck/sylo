# include "sylo/triggers/rtrig.hpp"

RTrig::RTrig() : last(false) {
    // No further instructions required
}

bool RTrig::exec(bool in) {
    bool result = (!last) & in;
    last = in;
    return result;
}

bool RTrig::operator()(bool in) {
    return this->exec(in);
}