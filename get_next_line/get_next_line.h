/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:29:48 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/29 17:41:38 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*move_end_line(const char *str, const char *last_line);
#endif
