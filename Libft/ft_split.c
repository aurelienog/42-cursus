/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:33:32 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/19 09:42:26 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	words;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ptr = ft_calloc(words + 1, sizeof(char *));
	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			j = i;
			while (s[j] != c && s[j] != '\0')
				j++;
			ptr[words] = (char *)ft_substr((char *)s, i, j - i);
			words++;
		}
		i++;
	}
	return (ptr);
}
/*
#include <stddef.h>
#include "libft.h"
#include <stdio.h>

int     main(void)
int     main(void)
{
        char **str = ft_split("hello world hola mundo", ' ');
        size_t i = 0;

        while (str[i])
        {
                printf("%s", str[i]);
                free(str[i]);
                i++;
        }
        free(str);
        return (0);
}

*/
