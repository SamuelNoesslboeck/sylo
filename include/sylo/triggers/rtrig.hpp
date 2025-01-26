// ##########################################
// #    RTrig - Rising Trigger Component    #
// ##########################################
// >
// > Build for the Arduino framework!

# pragma once

# include <Arduino.h>

/// @brief A RTrig (Rising trigger) function block, as common in PLC programming
struct RTrig {
private: 
    /// @brief Helper variable to store the last state of the input signal
    bool last;

public:
    /// @brief Creates a new instance of an RTrig trigger component
    RTrig() : last(false) {
        // No further instructions required
    }

    /// @brief Executes the block, updating all internal variables and returning the output signal
    /// @param in The input signal of the block
    /// @return The output signal of the block
    bool exec(bool in) {
        bool result = (!last) & in;
        last = in;
        return result;
    }

    /// @brief Executes the block, updating all internal variables and returning the output signal
    /// @param in The input signal of the block
    /// @return The output signal of the block
    bool operator()(bool in) {
        return this->exec(in);
    }
};