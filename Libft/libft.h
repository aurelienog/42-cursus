/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:36:11 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/16 16:33:45 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <strings.h>
#include <stdint.h>

/* ************************************************************************** */
/*				CHARACTER FUNCTIONS			      */
/* ************************************************************************** */

/** ft_isalpha - checks for an alphabetic character
* @param - character to convert
* @return - convert character or c if it is not lowercase or uppercase
*/
int		ft_isalpha(int c);

/** ft_isdigit - checks for a digit (0 through 9)
 * @param -  character to check
 * @return - 1 if c is numeric or 0 if it is not
 */
int		ft_isdigit(int c);

/** ft_isalnum - checks for an alphanumeric character
 * @param - character to check
 * @return - 1 if c is numeric or 0 if it is not
 */
int		ft_isalnum(int c);

/** ft_isascii - checks whether c is a 7-bit unsigned char value 
 * @param - character to check
 * @return - 1 if c is numeric or 0 if it is not
 */
int		ft_isascii(int c);

/** ft_isprint - checks for any printable character including space.
 * @param - character to check
 * @return - 1 if c is numeric or 0 if it is not
 */
int		ft_isprint(int c);

/** ft_toupper - convert lowercase letters to uppercase
 * @param - character to check
 * @return - convert character or c if it is not lowercase
 */
int		ft_toupper(int c);

/** ft_tolower - convert uppercase letters to lowercase
 * @param - character to check
 * @return - convert character or c if it is not uppercase
 */
int		ft_tolower(int c);

/* ************************************************************************** */
/*                            STRING FUNCTIONS                                */
/* ************************************************************************** */

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);

/** ft_substr - Allocates memory (using malloc(3)) and returns a substring
 * @param - s: The original string from which to create the
 * substring.
 * start: The starting index of the substring within ’s’.
 * len: The maximum length of the substring.
 * @return The substring or NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/** ft_strjoin - Allocates memory (using malloc(3)) and returns a new string
 * @param - s1: The prefix string
 * s2: The suffix string
 * @return The new string or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/** ft_strtrim - Allocates memory (using malloc(3)) and returns a new string 
 * @param - s1: The string to be trimmed.
 * set: The string containing the set of characters to be removed 
 * from the beginning and the end
 * @return The trimmed string or NULL if the allocation fails
 */
char	*ft_strtrim(char const *s1, char const *set);

/** ft_split - Allocates memory (using malloc(3)) and returns an array
 * of strings
 * @param - s: The string to be split
 * c: The delimiter character
 * @return The array of new strings or NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c);

/** ft_strmapi - Allocates memory (using malloc(3)) and applies the function f
 * to each character of the string s
 * @param - s: The string to iterate over
 * f: The function to apply to each character
 * @return - The string created from the successive applications of ’f’.
 * Returns NULL if the allocation fails
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* ************************************************************************** */
/*                            MEMORY FUNCTIONS                                */
/* ************************************************************************** */

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

/* ************************************************************************** */
/*                          CONVERSION FUNCTIONS                              */
/* ************************************************************************** */

int		ft_atoi(const char *nptr);

/** ft_itoa - Allocates memory (using malloc(3))  and returns a string
 * representing the integer received
 * @param - n : The integer to convert.
 * @return - The string representing the integer or NULL if the allocation fails.
 */
char	*ft_itoa(int n);
