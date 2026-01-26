#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	ft_printf("clone c: %c - fin\n", 'A');
           printf("origi c: %c - fin\n", 'A');

	ft_printf("clone %%: %% - fin\n");
           printf("origi %%: %% - fin\n");

	ft_printf("clone s: %s %s - fin\n", "hola", "mundo");
	   printf("origi s: %s %s - fin\n", "hola", "mundo");

	ft_printf("clone i: %i - fin\n", INT_MIN);
          printf("origi i: %i - fin\n", INT_MIN);
	
	ft_printf("clone x: %x - fin\n", INT_MIN);
           printf("origi x: %x - fin\n", INT_MIN);
	
	ft_printf("clone x: %X - fin\n", INT_MAX);
           printf("origi x: %X - fin\n", INT_MAX);

	ft_printf("clone p: %p - fin\n", "address");
           printf("origi p: %p - fin\n", "address");

	   unsigned int    num = 4294965;
	ft_printf("clone d: %d - fin\n", num);
           printf("origi d: %d - fin\n", num);

	unsigned int	max = 4294967295;
	ft_printf("clone u: %u - fin\n", max);
           printf("origi u: %u - fin\n", max);

	return (0);
}
