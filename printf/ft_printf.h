/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:14:27 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/26 16:58:03 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

int		ft_printf(const char *format, ...);
/* ************************************************************************** */
/*                            OUTPUT FUNCTIONS                                */
/* ************************************************************************** */

/** ft_putstr_fd - Outputs the string ’s’ to the specified file descriptor
 * @param - s: The string to output.
 * fd: The file descriptor on which to write
 * @return - none
 */
void	ft_putstr_fd(char *s, int fd);

/** ft_putnbr_fd - Outputs the integer ’n’ to the specified file descriptor
 * @param - s: The integer to output.
 * fd: The file descriptor on which to write
 * @return - none
 */
void	ft_putnbr_fd(int n, int fd);

/** ft_putchar_fd - Outputs the character ’c’ to the specified file descriptor
 * @param - c: The character to output
 * fd: The file descriptor on which to write
 * @return - none
 */
void	ft_putchar_fd(char c, int fd);

void    putnbr_hex(int n, char *base);

void	ft_unsigned_putnbr_fd(unsigned int n, int fd);

/* ************************************************************************** */
/*                            STRING FUNCTIONS                                */
/* ************************************************************************** */

/** ft_strchr - returns a pointer to the first occurrence of the character
 * in the string
 * @param : s : the original string
 * c : the character to find
 * @return - a pointer to the matched character or NULL
 */
char	*ft_strchr(const char *s, int c);
