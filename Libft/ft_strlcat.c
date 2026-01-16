/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:57:47 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/15 10:07:50 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	start;
	size_t	i;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	start = dest_len;
	i = 0;
	while (src[i] && i < size)
		dst[start++] = src[i++];
	dst[start] = '\0';
	return (src_len + dest_len);
}
/*
#include <stdio.h>
int     main(void)
{
        char    string[] = "hello";
        char    string2[] = " world";

        printf("%ld\n", ft_strlcat(string, string2, (unsigned int)3));
        printf("%s", string);
        return (0);
}*/
