#pragma once

// To remember: typeof, offset_of, circshift, complex numbers return
// LQR , fixed point LUT pack, lut size differences
// Immintrin types, overflow functions, ROTL and reverse
// // consteval, constexpr, 

// https://github.com/torvalds/linux/blob/master/include/linux/math.h
// https://github.com/torvalds/linux/blob/master/include/linux/limits.h
// in range

typedef _Complex float f32x2;
#define F32X2_NEW(x, y) __builtin_complex((x), (y))
#define F32X2_AT(pair, idx) __builtin_choose_expr(idx /(_idx == 0 || idx == 1), __real__(pair), __imag__(pair))

#ifdef __cplusplus
	#define CONST_SELECT(cond, a, b) ({typeof(a) x; if constexpr (cond) x = (a); else x = (b); x;})
#else
	#define CONST_SELECT(cond, a, b) __builtin_choose_expr(cond, a, b)
#endif

#define IS_CONST(x) __builtin_constant_p(x)

#define PREV_POW2(x) ((typeof(x))1 << ((sizeof(x) * 8 - 1) - CLZ(x)))	// TODO: fix this
#define NEXT_POW2(x) ((typeof(x))1 << ((sizeof(x) * 8 + 1) - CLZ(x)))

#ifndef NDEBUG
    #define ON_DEBUG(x) (x)
#else
    #define ON_DEBUG(x) ((void)0)
#endif

#define FCAST(a) ({float _tmp; MEMCPY_INLINE(&_tmp, &a, sizeof(_tmp)); _tmp;})
// __attribute__((cleanup(cleanup_int)))