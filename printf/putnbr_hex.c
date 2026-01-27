/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:56:38 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/27 13:39:26 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_hex(unsigned int n, char *base)
{
	unsigned int	numbers[32];
	int				i;
	int				count;

	if (n == 0)
		return (write(1, "0", 1));
	i = 0;
	count = 0;
	while (n > 0)
	{
		numbers[i] = (n % 16);
		n /= 16;
		count++;
		i++;
	}
	i--;
	while (i > 0)
	{
		write(1, &base[numbers[i]], 1);
		i--;
	}
	write(1, &base[numbers[i]], 1);
	return (count);
}
/*
int	main(void)
{
	putnbr_hex(INT_MIN);
	return (0);
}*/
