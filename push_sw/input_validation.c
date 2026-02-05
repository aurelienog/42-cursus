/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:50:50 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/04 14:37:40 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
/*
int     ft_atoi(const char *nptr)
{
        long int        res;
        long int        i;
        long int        sign;

        res = 0;
        i = 0;
        sign = 1;
        while (nptr[i] == ' ' || ((nptr[i] <= 13) && (nptr[i] >= 9)))
                i++;
        if (nptr[i] == '-' || nptr[i] == '+')
        {
                if (nptr[i] == '-')
                        sign = -1;
                i++;
        }
        while (nptr[i] != '\0' && ((nptr[i] >= '0') && (nptr[i] <= '9')))
        {
                res = (res * 10) + (nptr[i] - '0');
                i++;
                if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
                        return (0);
        }
        return (res * sign);
}


int     ft_isdigit(int c)
{
        if (48 <= c && c <= 57)
                return (1);
        else
                return (0);
}

int     ft_strncmp(const char *s1, const char *s2, size_t n)
{
        long unsigned int       i;

        i = 0;
        while (i < n)
        {
                if (s1[i] != s2[i])
                        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
                i++;
        }
        return (0);
}

size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (str[i] != '\0')
                i++;
        return (i);
}


int	ft_is_command(char *str)
{
	if (ft_strncmp(str, "--simple", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--medium", 8) == 0)
		return (1);
	else if (ft_strncmp(str, "--complex", 9) == 0)
		return (1);
	else if (ft_strncmp(str, "--adaptative", 12) == 0)
		return (1);
	else if (ft_strncmp(str, "--bench", 7) == 0)
		return (1);
	else
		return (0);
}
*/
int	ft_is_int(char *src)
{
	int	i;

	i = 0;
	if (src[i] == '-')
		i++;
	while (src[i] != '\0')
	{
		if (ft_isdigit(src[i]) != 1)
			return (0);
		i++;
	}
	if ((ft_atoi(src) == 0) && (ft_strlen(src) != 1 && ft_strlen(src) != 2))
		return (0);
	return (1);
}

int	ft_is_repetition(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_str_valid(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_is_int(str[i]) != 1)
			return (0);
		i++;
	}
	if (ft_is_repetition(str) == 0)
		return (0);
	return (1);
}
/*
int	ft_is_command_valid(char *str1, char *str2)
{
	if((ft_strncmp(str1, "--bench", 7) != 0) || ft_strlen(str1) != 7)
	{
		if (ft_strncmp(str2, "--bench", 7) != 0 || ft_strlen(str2) != 7)
			return (0);
	}
	if (ft_strncmp(str1, "--bench", 7) == 0 && ft_strlen(str1) == 7)
	{
		if (ft_strncmp(str2, "--bench", 7) == 0 && ft_strlen(str2) == 7)
			return (0);
	}
	return (1);
}*/

int	ft_is_input_valid(char **str)
{
	int	i;

	i = 1;
	if (ft_is_command(str[i]) == 1)
	{
		i++;
		if (ft_is_command(str[i]) == 1)
		{
			if (ft_is_command_valid(str[1], str[2]) == 0)
				return (0);
			i++;
		}
		else if (ft_is_int(str[i]) != 1)
			return (0);
	}
	if (ft_is_str_valid(&str[i]) != 1)
	{
		return (0);
	}
	return (1);
}
/*
int	main(void)
{
	char	**test;
	int	i = 0;

	test = malloc(7 * sizeof(char *));
	test[0] = "Le silence éternel de ces espaces infinis m’effraie\0";
	test[1] = "--bench";
	test[2] = "-544655";
	test[3] = "-0";
	test[4] = "10";
	test[5] = "-68";
	test[6] = NULL;
	
	i = ft_is_input_valid(test);
	printf ("Les resultat est : %d\n", i);
	while (i <= 5)
	{
		printf ("%s\n", test[i]);
		i++;
	}
	free (test);
	return (0);
}*/
