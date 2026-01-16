/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:35:57 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/16 17:00:22 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	length;
	char	*str;

	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	str = ft_calloc((length + 1), sizeof(char));
	i = 0;
	while (s[i])
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
