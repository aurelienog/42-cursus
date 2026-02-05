/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:28:20 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/05 14:44:45 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		strlen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	strlen = ft_strlen(s);
	if (len > strlen - start)
		len = strlen - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while ((i < len))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
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

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;
	char	*cpy;

	cpy = (char *)s;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = cpy[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*newstrjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!str1 || !str2)
		return (free(str1), str1 = NULL, NULL);
	new = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!new)
		return (free(str1), str1 = NULL, NULL);
	i = 0;
	while (str1[i])
	{
		new[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		new[i] = str2[j++];
		i++;
	}
	new[i] = '\0';
	if (str1)
		free(str1);
	return (new);
}
