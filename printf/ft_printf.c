/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:26:33 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/26 16:57:11 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	dispatch(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd((va_arg(args, int)), 1);
	else if (c == 's')
		ft_putstr_fd((char *)(va_arg(args, char *)), 1);
	else if (c == 'i' || c == 'd')
		ft_putnbr_fd((va_arg(args, int)), 1);
	else if (c == 'x')
		putnbr_hex(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		putnbr_hex(va_arg(args, int), "0123456789ABCDEF");
//	else if (c == 'p')
//		print_adress
	else if (c == 'u')
		ft_unsigned_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

int	ft_printf(const char *format, ...)
{
	size_t		i;
	char		*conversion;
	const char	*specifiers;
	va_list		args;

	va_start(args, format);
	specifiers = "cspdiuxX%";
	i = 0;
	while (format[i])
	{
		conversion = ft_strchr(specifiers, (int)format[i + 1]);
		if (format[i] == '%' && conversion)
		{
			dispatch(conversion[0], args);
			i++;
		}
		else
			ft_putchar_fd((char)format[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}
