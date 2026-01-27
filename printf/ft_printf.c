/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:26:33 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/27 13:06:38 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dispatch(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar_fd((va_arg(*args, int)), 1));
	else if (c == 's')
		return (ft_putstr_fd((char *)(va_arg(*args, char *)), 1));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_fd((va_arg(*args, int)), 1));
	else if (c == 'x')
		return (putnbr_hex(va_arg(*args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (putnbr_hex(va_arg(*args, int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (print_address(va_arg(*args, void *), 1));
	else if (c == 'u')
		return (ft_unsigned_putnbr_fd(va_arg(*args, unsigned int), 1));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t		i;
	char		*conversion;
	const char	*specifiers;
	va_list		args;
	int			count;

	va_start(args, format);
	specifiers = "cspdiuxX%";
	i = 0;
	count = 0;
	while (format[i])
	{
		conversion = ft_strchr(specifiers, (int)format[i + 1]);
		if (format[i] == '%' && conversion)
		{
			count += dispatch(conversion[0], &args);
			i++;
		}
		else
			count += ft_putchar_fd((char)format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
