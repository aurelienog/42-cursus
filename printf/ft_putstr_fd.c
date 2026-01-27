/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:17:20 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/27 12:07:35 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	int		count;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	count = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		count++;
		i++;
	}
	return (count);
}
