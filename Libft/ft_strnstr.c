/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 09:21:27 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/15 10:18:15 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(char *str, char *to_find)
{
	size_t	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (ft_strcmp((char *)&big[i], (char *)little))
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int     main(void)
{
        char    *str = "helloworld";
        char    *str1 = "world";
        printf("%s", ft_strnstr(str, str1, 10));
        return (0);
}*/
