// ###########################################
// #    FTrig - Falling Trigger Component    #
// ###########################################
//
// > Version 0.1.0
// >
// > Build for the Arduino framework!

# pragma once

/// @brief A FTrig (Falling trigger) function block, as common in PLC programming
struct FTrig {
private: 
    /// @brief Helper variable to store the last state of the input signal
    bool last;

public:
    /// @brief Creates a new instance of an FTrig trigger component
    FTrig() : last(false) {
        // No further instructions required
    }
    
    /// @brief Executes the block, updating all internal variables and returning the output signal
    /// @param in The input signal of the block
    /// @return The output signal of the block
    bool exec(bool in) {
        bool result = last & (!in);
        last = in;
        return result;
    }
};