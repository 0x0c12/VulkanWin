// Hopefully, this remains untouched for the lifetime of this project...

#pragma once

// uint types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// sint types
typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

// fint types
typedef float f32;
typedef double f64;

// bool types
typedef int b32;
typedef char b8;

// static asserts
#if defined(__clang__) || defined(gcc)
    #define STATIC_ASSERT _Static_assert
#else
    #define STATIC_ASSERT static_assert
#endif

// size-checking for all types
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes");

#define TRUE 1
#define FALSE 0

// platform detect
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define VKW_PLATFORM_WINDOWS 1
    #ifndef _WIN64
    #error "64-bit is required on windows!"
    #endif
#else
    #error "Unsupported platform[for now ;)]"
#endif

#ifdef VKW_EXPORT
    #ifdef _MSC_VER
        #define VKW_API __declspec(dllexport)
    #else
        #define VKW_API __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define VKW_API __declspec(dllimport)
    #else
        #define VKW_API
    #endif
#endif
