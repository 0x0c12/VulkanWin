#pragma once

#include "defines.h"

// Toggle for assertions(comment to disable)
#define VKW_ASSERTIONS_ENABLED

#ifdef VKW_ASSERTIONS_ENABLED
    #if _MSC_VER
        #include <intrin.h>
        #define DebugBreak() __debugbreak()
    #else
        #define DebugBreak() __builtin_trap()
    #endif

    VKW_API void ReportAssertionFailure(const char* expression, const char* message, const char* file, i32 line);

    #define VKW_ASSERT(expr)                                          \
        {                                                             \
            if(expr)                                                  \
            {}                                                        \
            else                                                      \
            {                                                         \
                ReportAssertionFailure(#expr, "", __FILE__, __LINE__); \
                DebugBreak();                                         \
            }                                                         \
        }
        
    #define VKW_ASSERT_MSG(expr, msg)                                \
        {                                                            \
            if(expr)                                                 \
            {}                                                       \
            else                                                     \
            {                                                        \
              ReportAssertionFailure(#expr, msg, __FILE__, __LINE__); \
              DebugBreak();                                          \
            }                                                        \
        }

    #ifdef _DEBUG
        #define VKW_ASSERT_DEBUG(expr, msg)                              \
            {                                                            \
                if(expr)                                                 \
                {}                                                       \
                else                                                     \
                {                                                        \
                  ReportAssertionFailure(#expr, msg, __FILE__, __LINE__); \
                  DebugBreak();                                          \
                }                                                        \
            }                                                            
    #else
        #define VKW_ASSERT_DEBUG(expr)
    #endif

#else
    #define VKW_ASSERT(expr) 
    #define VKW_ASSERT_MSG(expr, msg)
    #define VKW_ASSERT_DEBUG(expr)
#endif
