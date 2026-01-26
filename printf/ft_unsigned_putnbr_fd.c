/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:48:02 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/26 17:03:57 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_putnbr_fd(unsigned n, int fd)
{
	unsigned int		i;
	char	digits[33];

	i = 0;
	while (n > 0)
	{
		digits[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	digits[i] = n;
	while (i > 0)
	{
		write(fd, &(digits[i]), 1);
		i--;
	}
	write(fd, &(digits[i]), 1);
}

