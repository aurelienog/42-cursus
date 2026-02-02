/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:28:20 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/02 13:25:17 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*newstrjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!str1)
		new = malloc((ft_strlen(str2) + 1) * sizeof(char));
	else
		new = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!new)
	{
		free(str1);
		return (NULL);
	}
	i = 0;
	while(str1 && str1[i])
	{
		new[i] = str1[i];
		i++;
	}
	j = 0;
	while(str2[j])
		new[i++] = str2[j++];
	new[i] = '\0';
	if (str1)
		free(str1);
	return (new);
}
