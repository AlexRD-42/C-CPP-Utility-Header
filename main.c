#include "types.h"
#include "builtins.h"
#include "helpers.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	int a = 4;
	int b = 5;

	__builtin_memcpy(&a, &b, sizeof(a));
	// MEMCPY_BUILTIN(&a, &b, sizeof(a));
	printf("%d", b);
}
