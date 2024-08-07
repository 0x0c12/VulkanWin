#pragma once

#include "defines.h"

// Some macros to manipulate log levels
#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// Strip out Debug and Trace log(engine side) for release builds
#if VKW_RELEASE == 1
    #define LOG_DEBUG_ENABLED 0
    #define LOG_TRACE_ENABLED 0
#endif

// Supported log levels for VKWin are defined in this
typedef enum logLevel {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} logLevel;

// Lifetime functions for the logging component
b8 LogInit(); // Start-up the logging system
void LogShutdown(); // Stop the logging system

VKW_API void LogOutput(logLevel level, const char* message, ...);

// Utility macros to be used by user to actually log.
// The engine at the moment, expects user(game developer) to 
#define VKW_LOG_FATAL(message, ...) LogOutput(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef VKW_LOG_ERROR
    #define VKW_LOG_ERROR(message, ...) LogOutput(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
    #define VKW_LOG_WARN(message, ...) LogOutput(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
    #define VKW_LOG_WARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
    #define VKW_LOG_INFO(message, ...) LogOutput(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
    #define VKW_LOG_INFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
    #define VKW_LOG_DEBUG(message, ...) LogOutput(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
    #define VKW_LOG_DEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
    #define VKW_LOG_TRACE(message, ...) LogOutput(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
    #define VKW_LOG_TRACE(message, ...)
#endif
