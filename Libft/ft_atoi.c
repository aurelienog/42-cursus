/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:43:19 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 08:40:47 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	number = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + nptr[i++] - '0';
	}
	return (number * sign);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*string = "       ---+-+1234eaw45";

	printf("%d", ft_atoi(string));
	return (0);
}*/
