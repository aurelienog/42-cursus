/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 11:04:33 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/21 08:56:11 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*buffer;
	const unsigned char	*copysrc;

	if (!dest || !src)
		return (NULL);
	i = 0;
	buffer = (unsigned char *)dest;
	copysrc = (const unsigned char *)src;
	while (i < n)
	{
		buffer[i] = copysrc[i];
		i++;
	}
	return (dest);
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
