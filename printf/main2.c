#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int	ret_c;
	int	ret_o;
	int	a;

	a = 42;

	/* ===================== %c ===================== */
	ret_c = ft_printf("clone c: [%c]\n", 'A');
	ret_o = printf   ("origi c: [%c]\n", 'A');
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	ret_c = ft_printf("clone c null: [%c]\n", '\0');
	ret_o = printf   ("origi c null: [%c]\n", '\0');
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	/* ===================== %% ===================== */
	ret_c = ft_printf("clone %%: %% %% %%\n");
	ret_o = printf   ("origi %%: %% %% %%\n");
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	/* ===================== %s ===================== */
	ret_c = ft_printf("clone s: [%s]\n", "hola");
	ret_o = printf   ("origi s: [%s]\n", "hola");
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	ret_c = ft_printf("clone s empty: [%s]\n", "");
	ret_o = printf   ("origi s empty: [%s]\n", "");
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	ret_c = ft_printf("clone s NULL: [%s]\n", NULL);
	ret_o = printf   ("origi s NULL: [%s]\n", (char *)NULL);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	/* ===================== %d / %i ===================== */
	ret_c = ft_printf("clone d zero: %d\n", 0);
	ret_o = printf   ("origi d zero: %d\n", 0);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	ret_c = ft_printf("clone d min: %d\n", INT_MIN);
	ret_o = printf   ("origi d min: %d\n", INT_MIN);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	ret_c = ft_printf("clone d max: %d\n", INT_MAX);
	ret_o = printf   ("origi d max: %d\n", INT_MAX);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	/* ===================== %u ===================== */
	ret_c = ft_printf("clone u zero: %u\n", 0);
	ret_o = printf   ("origi u zero: %u\n", 0);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	ret_c = ft_printf("clone u max: %u\n", UINT_MAX);
	ret_o = printf   ("origi u max: %u\n", UINT_MAX);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	/* ===================== %x / %X ===================== */
	ret_c = ft_printf("clone x zero: %x\n", 0);
	ret_o = printf   ("origi x zero: %x\n", 0);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	ret_c = ft_printf("clone x neg: %x\n", -1);
	ret_o = printf   ("origi x neg: %x\n", -1);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	ret_c = ft_printf("clone X max: %X\n", UINT_MAX);
	ret_o = printf   ("origi X max: %X\n", UINT_MAX);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	/* ===================== %p ===================== */
	ret_c = ft_printf("clone p NULL: %p\n", NULL);
	ret_o = printf   ("origi p NULL: %p\n", NULL);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	ret_c = ft_printf("clone p var: %p\n", &a);
	ret_o = printf   ("origi p var: %p\n", &a);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	ret_c = ft_printf("clone p str: %p\n", "hola");
	ret_o = printf   ("origi p str: %p\n", "hola");
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	/* ===================== MIX ===================== */
	ret_c = ft_printf("clone mix: %c %s %d %u %x %X %p %%\n",
			'A', NULL, -42, 42, 42, 42, &a);
	ret_o = printf   ("origi mix: %c %s %d %u %x %X %p %%\n",
			'A', (char *)NULL, -42, 42, 42, 42, &a);
	printf("ret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	/* ===================== TRAILING %% ===================== */
	ret_c = ft_printf("clone trailing %%");
	ret_o = printf   ("origi trailing %%");
	printf("\nret clone: %d | ret origin: %d\n\n", ret_c, ret_o);

	return (0);
}

