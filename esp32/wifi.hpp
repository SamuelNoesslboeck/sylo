// #
// #    WIFI-
// #

# pragma once

# include <WiFi.h>
# include <sylo/logging.hpp>
# include <sylo/timing/timer.hpp>

# ifndef WIFI_RECONN_INTERVAL
    /// @brief The amount of milliseconds between reconnection tries when disconnected to the WiFi
    # define WIFI_RECONN_INTERVAL 3000
# endif

static Timer __wifi_reconn_timer;

/// @brief Reconnection function for WiFi, will skip if already connected
void wifi_reconnect() {
    if ((WiFi.status() != WL_CONNECTED) && (__wifi_reconn_timer.has_elapsed())) {
        log_infoln("> WiFi disconnected! Attempting to reconnect ... ");
        WiFi.disconnect();
        WiFi.reconnect();
        __wifi_reconn_timer.set(WIFI_RECONN_INTERVAL);
    } 
}