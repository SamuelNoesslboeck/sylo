# include "sylo/triggers/ftrig.hpp"

FTrig::FTrig() : last(false) {
    // No further instructions required
}
    
bool FTrig::exec(bool in) {
    bool result = last & (!in);
    last = in;
    return result;
}

bool FTrig::operator()(bool in) {
    return this->exec(in);
}