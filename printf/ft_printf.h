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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

/* ************************************************************************** */
/*                            OUTPUT FUNCTIONS                                */
/* ************************************************************************** */

/** ft_printf - write output to stdout according to a format that specifies
 * how subsequent arguments are converted for output
 * @param - format: The string to output
 * @return - the number of bytes printed
 */
int		ft_printf(const char *format, ...);

/** ft_putstr_fd - Outputs the string ’s’ to the given file descriptor
 * @param - s: The string to output.
 * fd: The file descriptor
 * @return - the number of bytes printed
 */
int		ft_putstr_fd(char *s, int fd);

/** ft_putnbr_fd - Outputs the integer ’n’ to the given file descriptor
 * @param - n: The integer to output.
 * fd: The file descriptor
 * @return - the number of bytes printed
 */
int		ft_putnbr_fd(int n, int fd);

/** ft_putchar_fd - outputs the character ’c’
 * @param - c: The character to output
 * fd: The file descriptor
 * @return - the number of bytes printed
 */
int		ft_putchar_fd(char c, int fd);

/** ft_putnbr_hex - convert ’n’ to the given base and outputs the result
 * @param - n: the unsigned integer to output.
 * base: the base string
 * @return - the number of bytes printed
 */
int		putnbr_hex(unsigned int n, char *base);

/** ft_unsigned_putnbr_fd - outputs the unsigned integer n
 * @param - n: The unsigned integer to output.
 * fd: The file descriptor
 * @return - the number of bytes printed
 */
int		ft_unsigned_putnbr_fd(unsigned int n, int fd);

/** print_address - outputs the memory address of the pointer received
 * @param - ptr: the pointer whose address will be printed
 * fd: The file descriptor 
 * @return - the number of bytes printed
 */
int		print_address(void *ptr, int fd);

/* ************************************************************************** */
/*                            STRING FUNCTIONS                                */
/* ************************************************************************** */

/** ft_strchr - locate the first occurrence of c in the string s
 * @param : s : the string to search
 * c : the character to locate
 * @return - a pointer to the character found or NULL
 */
char	*ft_strchr(const char *s, int c);

#endif
