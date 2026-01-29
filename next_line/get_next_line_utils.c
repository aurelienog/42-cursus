/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:28:20 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/29 17:35:56 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_end_line(const char *str, const char *last_line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*last_line)
		return ((char *)str);
	while (str[i])
	{
		while (str[i] == last_line[j])
		{
			i++;
			j++;
		}
		if (last_line[j] == '\0')
			return ((char *) &str[i]);
		i = (i - j);
		j = 0;
		i++;
	}
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
