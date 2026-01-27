/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:48:02 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/27 12:35:30 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	unsigned int	i;
	char			digits[33];
	int				count;

	if (n == 0)
	{
    		write(1, "0", 1);
    		return (1);
	}
	i = 0;
	count = 0;
	while (n > 0)
	{
		digits[i] = (n % 10) + '0';
		n /= 10;
		count++;
		i++;
	}
	digits[i] = n;
	while (i > 0)
	{
		write(fd, &(digits[i]), 1);
		i--;
	}
	write(fd, &(digits[i]), 1);
	return (count);
}
