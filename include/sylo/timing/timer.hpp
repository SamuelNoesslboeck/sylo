// ##################################
// #    Timer - Timing component    #
// ##################################
// >
// > Build for the Arduino framework!

# pragma once

# include <inttypes.h>

class Timer {
private:
    uint32_t set_stamp = 0;
    uint32_t duration = 0;

public:
    Timer();

    Timer(uint32_t duration);

    void set();

    void set(uint32_t duration);

    bool running();

    bool has_elapsed();
};