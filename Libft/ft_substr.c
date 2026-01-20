/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 09:25:22 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/20 09:10:21 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while ((i < len))
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str;

	str = ft_substr("helloworldee", 0, 12);
	printf("%s", str);
	free(str);
	return (0);
}*/
