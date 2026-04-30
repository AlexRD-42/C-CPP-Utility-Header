# Introduction
This header file is more or less designed to be a language extension through the use of compiler builtins and language features

It targets GCC/CLANG (MSVC has some peculiarities that are hard to standardize), and aims to provide a unified interface for both C/C++ and GCC/CLANG features. It also adds some useful macros.

For now, in development, it is split in several header files. But ultimately this will be a one header file include.

# Objectives
The goal of this header file is to provide:

### 1. Unified terminology for shared and equivalent resources in C/C++
For example, restrict doesn't exist in iso C++, but it does through compiler extensions
Or bool isn't a type in regular C
```c
#ifdef __cplusplus
	#define restrict __restrict__
#else
	#define static_assert(cond, msg) _Static_assert(cond, msg)
#endif
```

### 2. Unified terminology for compiler attributes in both C/C++ and CLANG/GCC
The ultimate goal is to 
```c
#if defined(__clang__)
	#define ASSUME(x)	__builtin_assume(x)
#elif defined(__GNUC__)
	#define ASSUME(x) ((x) ? (void)0 : __builtin_unreachable())
#endif
```

### 3. Nicer compiler agnostic interface for useful compiler builtins
```c
#define CLZ(x)	__builtin_clzll(x)

#if defined(__clang__) && __has_builtin(__builtin_memcpy_inline)
	#define MEMCPY_INLINE(dst, src, n)	__builtin_memcpy_inline(dst, src, n)
#else
	#define MEMCPY_INLINE(dst, src, n)	__builtin_memcpy(dst, src, n)
#endif
```

### 4. Generic macro utilities and constants that are useful in any context

```c
#define ARRAY_COUNT(arr)	(sizeof(arr) / sizeof((arr)[0]))
#define ARRAY_END(arr)		(&(arr)[ARRAY_SIZE(arr)])
#define SWAP(a, b)			({__auto_type ___tmp = (a); (a) = (b); (b) = ___tmp; (void)0;})
#define CLAMP(x, low, high)	MAX(low, MIN(x, high))
#define ALIGN_UP(x, a)		(((x) + ((a) - 1)) & ~((a) - 1))
#define WORD_SIZE	sizeof(size_t)
#define WORD_BITS	(WORD_SIZE * CHAR_BIT)
#define PI			3.141592653589793238462643383279502884
```

### 5. Type standardization
```c
typedef int8_t		i8;
typedef uint8_t		u8;
typedef int16_t		i16;
typedef uint16_t	u16;
typedef int32_t		i32;
```
