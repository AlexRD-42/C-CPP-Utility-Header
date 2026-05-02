#pragma once
#include "header.h"

#define ALWAYS_INLINE	static inline __attribute__((always_inline))
#define NOINLINE		__attribute__((noinline))
#define PURE			__attribute__((pure))			// Function produces no observable side effects (may read from memory)
#define KPURE			__attribute__((const))			// Function depends only on its arguments (doesn't read from memory)
#define PACKED			__attribute__((packed))			// Struct has no padding
#define ALIGNED(n)		__attribute__((aligned(n)))
#define COLD			__attribute__(cold)
#define HOT				__attribute__(hot)
#define FLATTEN			__attribute__((flatten))		// Function calls inside this function are aggressively inlined

#define UNREACHABLE()	__builtin_unreachable()
#define LIKELY(x)		__builtin_expect(!!(x), 1)
#define UNLIKELY(x)		__builtin_expect(!!(x), 0)
#if defined(__clang__)
	#define ASSUME(x)	__builtin_assume(x)
#elif defined(__GNUC__)
	#define ASSUME(x) ((x) ? (void)0 : __builtin_unreachable())
#endif

#define MEMCPY_BUILTIN(dst, src, n)		__builtin_memcpy(dst, src, n)
#define MEMMOVE_BUILTIN(dst, src, n)	__builtin_memmove(dst, src, n)
#define MEMSET_BUILTIN(dst, val, n)		__builtin_memset(dst, val, n)	// TODO: memchr

#if defined(__clang__) && __has_builtin(__builtin_memcpy_inline)
	#define MEMCPY_INLINE(dst, src, n)	__builtin_memcpy_inline(dst, src, n)
#else
	#define MEMCPY_INLINE(dst, src, n)	__builtin_memcpy(dst, src, n)
#endif

#define CLZ(x)			__builtin_clzll(x)
#define CTZ(x)			__builtin_ctzll(x)
#define POPCOUNT(x)		__builtin_popcountll(x)
#define FFS(x)			__builtin_ffsll(x)
#define PARITY(x)		__builtin_parityll(x)
#define BSWAP16(x)		__builtin_bswap16(x)
#define BSWAP32(x)		__builtin_bswap32(x)
#define BSWAP64(x)		__builtin_bswap64(x)
#define BITREVERSE(x)	__builtin_bitreverse64(x)	// TODO: CLANG SPECIFIC
