#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	main(void)
{
	char *str = ft_strmapi("hello world\0", &ft_tolower());
	printf("%s", str);
	free(str);
	return (0);
}
