/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:07:11 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/15 10:20:12 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	length;
	int	i;

	length = ft_strlen(s);
	i = length - 1;
	if (c == '\0')
		return ((char *) &s[length]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}
/*
#include <stdio.h>

int     main(void)
{
        char *str = ft_strrchr("hello", 'e');
                printf("%c", *str);
        return (0);
}*/
