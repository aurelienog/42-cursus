/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:14:27 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/27 15:12:35 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

/* ************************************************************************** */
/*                            OUTPUT FUNCTIONS                                */
/* ************************************************************************** */

/** ft_printf - write output to stdout according to a format that specifies
 * how subsequent arguments are converted for output
 * @param - format: The string to output
 * @return - the number of bytes printed
 */
int		ft_printf(const char *format, ...);

/** ft_putstr_fd - Outputs the string ’s’ to the specified file descriptor
 * @param - s: The string to output.
 * fd: The file descriptor on which to write
 * @return - the number of bytes printed
 */
int		ft_putstr_fd(char *s, int fd);

/** ft_putnbr_fd - Outputs the integer ’n’ to the specified file descriptor
 * @param - n: The integer to output.
 * fd: The file descriptor on which to write
 * @return - the number of bytes printed
 */
int		ft_putnbr_fd(int n, int fd);

/** ft_putchar_fd - Outputs the character ’c’ to the specified file descriptor
 * @param - c: The character to output
 * fd: The file descriptor on which to write
 * @return - the number of bytes printed
 */
int		ft_putchar_fd(char c, int fd);

/** ft_putnbr_hex - convert ’n’ to the base and output the result
 * @param - n: the unsigned integer to output.
 * base: the base to convert to
 * @return - the number of bytes printed
 */
int		putnbr_hex(unsigned int n, char *base);

/** ft_unsigned_putnbr_fd - Outputs ’n’ to the specified file descriptor
 * @param - n: The unsigned integer to output.
 * fd: The file descriptor on which to write
 * @return - the number of bytes printed
 */
int		ft_unsigned_putnbr_fd(unsigned int n, int fd);

/** print_address - Outputs the memory address of the pointer received
 * @param - ptr: the pointer which address will be print
 * fd: The file descriptor on which to write
 * @return - the number of bytes printed
 */
int		print_address(void *ptr, int fd);

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
