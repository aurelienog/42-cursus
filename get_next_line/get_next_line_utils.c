/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:28:20 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/30 11:08:03 by aunoguei         ###   ########.fr       */
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
		if (last_line[j] == '\0' || last_line[j] == '\n')
			return ((char *) &str[i]);
		i = (i - j);
		j = 0;
		i++;
	}
	return (NULL);
}
