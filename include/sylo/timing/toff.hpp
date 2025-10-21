// #################################
// #    TOff - Timing component    #
// #################################
// >
// > Build for the Arduino framework!

# pragma once

# include <inttypes.h>

/// @brief A function block class common in PLC programming, used to keep input signals alive longer for a fixed period of time, the `phase`
class TOff {
private:
    /// @brief Timestamp in milliseconds of the last time the input signal has been `HIGH`
    uint32_t last;

public:
    /// @brief The phase (in milliseconds) regulates how long the output signal should be kept `HIGH`, when the input signal already dropped to `LOW`
    uint32_t phase; 

    /// @brief Creates a new instance of a TOff timing component
    /// @param phase The phase (in milliseconds) regulates how long the output signal should be kept `HIGH`, when the input signal already dropped to `LOW`
    TOff(uint32_t phase);

    /// @brief Executes the block, updating all internal variables and returning the output signal
    /// @param in The input signal of the block
    /// @return The output signal of the block
    bool exec(bool in);

    /// @brief Returns the elapsed time (in milliseconds) since the last `HIGH` on the input signal
    uint32_t elapsed_time();

    /// @brief Executes the block, updating all internal variables and returning the output signal
    /// @param in The input signal of the block
    /// @return The output signal of the block
    bool operator()(bool in);
}; 