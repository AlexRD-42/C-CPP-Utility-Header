#pragma once
#include "header.h"

typedef int8_t			i8;
typedef uint8_t			u8;
typedef int16_t			i16;
typedef uint16_t		u16;
typedef int32_t			i32;
typedef uint32_t		u32;
typedef int64_t			i64;
typedef uint64_t		u64;
typedef float			f32;
typedef double			f64;	// Should I include 128?
typedef size_t			usize;
typedef ptrdiff_t		isize;
typedef unsigned char	uchar;	// For completeness, to mirror platform's type
typedef unsigned short	ushort;
typedef unsigned int	uint;
typedef unsigned long	ulong;

/*
 * Multiple statements in one line to preserve line count (its not that ugly)
 * Unions might be a bit complicated for cross compatibility with C++ given the
 * nature of how unions work in C++
 *
 * It might be better to create generic bit cast functions for type punning
 */

typedef union
{
	uint8_t u8[4]; uint16_t u16[2]; uint32_t u32;
	int8_t i8[4]; int16_t i16[2]; int32_t i32;
	float f32;
}	m32;

typedef union
{
	uint8_t u8[8]; uint16_t u16[4]; uint32_t u32[2]; uint64_t u64;
	int8_t i8[8]; int16_t i16[4]; int32_t i32[2]; int64_t i64;
	float f32; double f64;
}	m64;
