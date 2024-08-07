#include "logger.h"
#include "asserts.h"

// TODO: temporary direct platform interface
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void ReportAssertionFailure(const char* expression, const char* message, const char* file, i32 line)
{
     LogOutput(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: %s, in file: %s, line: %d\n", expression, message, file, line);
}

b8 LogInit()
{
    // TODO: Create a log-file, comes with File I/O
    return TRUE;
}

void LogShutdown()
{
    // TODO: clean-up logger read/write queue
}

void LogOutput(logLevel level, const char* message, ...)
{
     const char* level_strings[6] = {"[FATAL]: ", "[ERROR]: ", "[WARN]: ", "[INFO]: ", "[DEBUG]: ", "[TRACE]: "};
     // b8 is_error = level < 2;

     // TODO: Temporary hack-solution, PLEASE fix this ASAP
     char out_message[32000];
     memset(out_message, 0, sizeof(out_message)); // zero out memory

     // NOTE: In-short, frick ya microsoft
     __builtin_va_list arg_ptr;
     va_start(arg_ptr, message);
     vsnprintf(out_message, 32000, message, arg_ptr);
     va_end(arg_ptr);

     char out_message_seq[32000];

     sprintf(out_message_seq, "%s%s\n", level_strings[level], out_message);

     // TODO: Setup platform-specific output in the platform impl layer
     printf("%s", out_message_seq);
}
