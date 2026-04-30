## Convert macros to statement expressions 
See if it's worth it to convert, because it means that there will be an over-reliance on GCC

## Figure out a cross language solution for constexpr
That involves both the choose expr, builtin constant, generic constexpr and consteval

#ifdef __cplusplus
	#define CONST_SELECT(cond, a, b) ({typeof(a) x; if constexpr (cond) x = (a); else x = (b); x;})
#else
	#define CONST_SELECT(cond, a, b) __builtin_choose_expr(cond, a, b)
#endif

#define IS_CONST(x) __builtin_constant_p(x)