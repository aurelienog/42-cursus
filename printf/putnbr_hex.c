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

void	putnbr_hex(int n, char *base)
{
	long	num;
	long	numbers[30];
	int		i;

	num = (long) n;
	if (num == 0)
		write(1, "0", 1);
	if (num < 0)
		num *= -1;
	i = 0;
	while (num > 0)
	{
		numbers[i] = (num % 16);
		num /= 16;
		i++;
	}
	while (i-- > 0)
		write(1, &base[numbers[i]], 1);
}
/*
int	main(void)
{
	putnbr_hex(INT_MIN);
	return (0);
}*/
