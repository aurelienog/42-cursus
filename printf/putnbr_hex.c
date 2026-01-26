/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:56:38 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/26 15:38:41 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_hex(unsigned int n, char *base)
{
	unsigned int	num;
	unsigned int	numbers[30];
	int		count;
	int		i;

	num = n;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	count = 0;
	while (num > 0)
	{
		numbers[i] = (num % 16);
		num /= 16;
		i++;
		count++;
	}
	while (i-- > 0)
		write(1, &base[numbers[i]], 1);
	return (count);
}
/*
int	main(void)
{
	putnbr_hex(INT_MIN);
	return (0);
}*/
