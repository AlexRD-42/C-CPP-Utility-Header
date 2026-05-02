#pragma once

#ifdef __cplusplus
	#include <cstddef>
	#include <cstdint>
	#include <climits>
	#define restrict __restrict__
#else
	#include <stddef.h>
	#include <stdint.h>
	#include <stdbool.h>
	#include <limits.h>
    #if __STDC_VERSION__ < 202311L
        #define auto __auto_type
		#define static_assert(cond, msg) _Static_assert(cond, msg)
    #endif
#endif

#define WORD_SIZE	sizeof(size_t)
#define WORD_BITS	(WORD_SIZE * CHAR_BIT)
#define PI			3.141592653589793238462643383279502884	// TODO: get actual double representation on these
#define EULER		2.718281828459045235360287471352662497	// TODO: get actual double representation on these
#define KLOG2		0.301029995663981195213738894724493026	// TODO: this might be useless
#define DEG2RAD		(PI / 180.0)							// TODO: get actual double representation on these
#define RAD2DEG		(180.0 / PI)							// TODO: get actual double representation on these

#ifdef __cplusplus
	#define ALIGN_SIZE	alignof(std::max_align_t)
#else
	#define ALIGN_SIZE	_Alignof(max_align_t)
#endif
