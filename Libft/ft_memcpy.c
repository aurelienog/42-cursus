/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:04:33 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/15 09:38:43 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*buffer;
	unsigned char		*copysrc;

	i = 0;
	buffer = (unsigned char *)dest;
	copysrc = (unsigned char *)src;
	while (n--)
	{
		buffer[i] = copysrc[i];
		i++;
	}
	return ((void *)dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[10];
	ft_memcpy(dest, "hello", 3);
	printf("%s", dest);
	return (0);
}*/
