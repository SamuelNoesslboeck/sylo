# pragma once

// Helper int types
typedef char i8;
typedef short i16;
typedef int i32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

// Special types
enum class Direction : bool {
    CW = true,
    CCW = false
}; 