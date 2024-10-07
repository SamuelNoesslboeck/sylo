// ################
// #   LOGGING    #
// ################
// 
// > Version: 0.1.0
// >
// > Build for the Arduino framework!

# pragma once

# include "logging_levels.hpp"

# ifndef LOG_LEVEL
    /// @brief Defines the level of logging, can be set to a log level from "logging_levels.hpp", default is `LOG_LEVEL_INFO`
    # define LOG_LEVEL LOG_LEVEL_INFO
# endif

# ifndef LOG_SERIAL
    /// @brief The serial interface used for printing out logging arguments, default is `Serial`
    # define LOG_SERIAL Serial
# endif

/// @brief Initializes the debug `Serial` with the given baud rate `baud`
# define init_logging(baud) LOG_SERIAL.begin(baud)

// Error level

    /// @brief Prints an argument to the log `Serial` defined with `LOG_SERIAL` if `LOG_LEVEL` is at least `LOG_LEVEL_ERROR`
    # define log_error(__arg) if (LOG_LEVEL > LOG_LEVEL_NONE) { LOG_SERIAL.print(__arg); }
    /// @brief Prints an argument to the log `Serial` defined with `LOG_SERIAL` if `LOG_LEVEL` is at least `LOG_LEVEL_ERROR`
    # define log_errorln(__arg) if (LOG_LEVEL > LOG_LEVEL_NONE) { LOG_SERIAL.println(__arg); }

//

// Warn level

    /// @brief Prints an argument to the log `Serial` defined with `LOG_SERIAL` if `LOG_LEVEL` is at least `LOG_LEVEL_WARN`
    # define log_warn(__arg) if (LOG_LEVEL > LOG_LEVEL_ERROR) { LOG_SERIAL.print(__arg); }
    /// @brief Prints an argument to the log `Serial` defined with `LOG_SERIAL` if `LOG_LEVEL` is at least `LOG_LEVEL_WARN`
    # define log_warnln(__arg) if (LOG_LEVEL > LOG_LEVEL_ERROR) { LOG_SERIAL.println(__arg); }

//

// Info level

    /// @brief Prints an argument to the log `Serial` defined with `LOG_SERIAL` if `LOG_LEVEL` is at least `LOG_LEVEL_INFO`
    # define log_info(__arg) if (LOG_LEVEL > LOG_LEVEL_WARN) { LOG_SERIAL.print(__arg); }
    /// @brief Prints an argument to the log `Serial` defined with `LOG_SERIAL` if `LOG_LEVEL` is at least `LOG_LEVEL_INFO`
    # define log_infoln(__arg) if (LOG_LEVEL > LOG_LEVEL_WARN) { LOG_SERIAL.println(__arg); }

//

// Debug level

    /// @brief Prints an argument to the log `Serial` defined with `LOG_SERIAL` if `LOG_LEVEL` is at least `LOG_LEVEL_DEBUG`
    # define log_debug(__arg) if (LOG_LEVEL > LOG_LEVEL_INFO) { LOG_SERIAL.print(__arg); }
    /// @brief Prints an argument to the log `Serial` defined with `LOG_SERIAL` if `LOG_LEVEL` is at least `LOG_LEVEL_DEBUG`
    # define log_debugln(__arg) if (LOG_LEVEL > LOG_LEVEL_INFO) { LOG_SERIAL.println(__arg); }

//

// Trace level

    /// @brief Prints an argument to the log `Serial` defined with `LOG_SERIAL` if `LOG_LEVEL` is `LOG_LEVEL_TRACE`
    # define log_trace(__arg) if (LOG_LEVEL > LOG_LEVEL_DEBUG) { LOG_SERIAL.print(__arg); }
    /// @brief Prints an argument to the log `Serial` defined with `LOG_SERIAL` if `LOG_LEVEL` is `LOG_LEVEL_TRACE`
    # define log_traceln(__arg) if (LOG_LEVEL > LOG_LEVEL_DEBUG) { LOG_SERIAL.println(__arg); }

// 