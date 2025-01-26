// ###############
// #    TYPES    #
// ###############
//
// Additional helper types for the arduino framework
//
// > Built for the Arduino framework!

# pragma once

/// Expresses a direction of movement
enum class Direction : bool {
    /// Indicates clockwise / positive movement
    CW = true,
    /// indicates counter-clockwise / negative movement
    CCW = false
}; 