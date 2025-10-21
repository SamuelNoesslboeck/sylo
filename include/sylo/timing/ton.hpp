// ################################
// #    TOn - Timing component    #
// ################################
// >
// > Build for the Arduino framework!

# pragma once

# include <inttypes.h>

/// @brief A function block class common in PLC programming, used to delay an output signal for a certain amount of time, the `phase`
class TOn {
private:
    /// @brief Timestamp in milliseconds since the input signal has been high
    uint32_t since;
    /// @brief Helper variable to track a constant input signal
    bool waiting;

public:
    /// @brief The phase (in milliseconds) regulates how long the output signal will be delayed from the constant input signal
    uint32_t phase; 

    /// @brief Creates a new instance of a TOn timing component
    /// @param phase The phase (in milliseconds) regulates how long the output signal will be delayed from the constant input signal
    TOn(uint32_t phase);

    /// @brief Executes the block, updating all internal variables and returning the output signal
    /// @param in The input signal of the block
    /// @return The output signal of the block
    bool exec(bool in);

    /// @brief Returns the time (in milliseconds) that the component got a constant `HIGH` input signal
    uint32_t elapsed_time();

    /// @brief Executes the block, updating all internal variables and returning the output signal
    /// @param in The input signal of the block
    /// @return The output signal of the block
    bool operator()(bool in);
}; 