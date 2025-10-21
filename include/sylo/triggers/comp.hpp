// ############################################
// #    Comp - Comparing trigger component    #
// ############################################
// >
// > Build for the Arduino framework!

# pragma once

# include <inttypes.h>

/// The comparision building block triggers, when a certain difference `delta` has been reached 
/// between an input value and the last value it has fired with. Useful for balancing out slightly fluctuating inputs from sensors
class Comp {
private:
    /// @brief The last value this component has triggered too
    int16_t last_trig_value;
    

public:
    /// @brief The difference in values to trigger a new event
    uint16_t delta_trig;
    /// @brief The difference between the last value `exec` hast been called with and the last value the block has been triggered with
    int16_t delta;

    /// Creates a new instance of a comparision building block
    /// @param delta_trig The value difference, should be according to the fluctuation/steps you want to create
    Comp(uint16_t delta_trig);

    /// Execute the block with a given input value
    /// @param value The input value to compare with previous values
    /// @return Whether the block has fired or not
    bool exec(int16_t value);

    /// Calls `exec()` with the given `value`
    bool operator()(int16_t value);
};