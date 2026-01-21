/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:59:20 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/21 08:55:34 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destcpy;
	const unsigned char	*cpysrc;
	size_t				i;

	if (!dest && !src)
		return (0);
	cpysrc = (const unsigned char *)src;
	destcpy = (unsigned char *)dest;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			destcpy[i] = cpysrc[i];
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			destcpy[n] = cpysrc[n];
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	buffer[4];

	buffer[4] = '\0';
	ft_memmove(buffer, "hello", 3);
	printf("%s", buffer);
	return (0);
}*/
