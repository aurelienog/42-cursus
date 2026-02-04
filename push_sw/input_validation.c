/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:50:50 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/03 17:29:27 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

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
	if (ft_strncmp(str, "--simple", ft_strlen(str)) == 0)
		return (1);
	else if (ft_strncmp(str, "--medium", ft_strlen(str)) == 0)
		return (1);
	else if (ft_strncmp(str, "--complex", ft_strlen(str)) == 0)
		return (1);
	else if (ft_strncmp(str, "--adaptative", ft_strlen(str)) == 0)
		return (1);
	else if (ft_strncmp(str, "--bench", ft_strlen(str)) == 0)
		return (1);
	else
		return (0);
}

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
	return (1);
}

int	ft_is_str_valid(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (*str[i])
	{
		if (ft_is_int(str[i]) != 1)
			return (0);
		while (*str[j])
		{
			if (ft_strncmp(str[i], str[j], ft_strlen(str[i])) == 0)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
		
int	ft_is_input_valid(char **str)
{
/*	int	i;

	i = 1;
	if (ft_is_command(str[i]) == 1)
	{
		i++;
		if (ft_is_command(str[i]) == 1)
		{
//			if ((str[i] != "--bench") && (str[i - 1] != "--bench"))
//					return (0);

			i++;
		}
	}*/
	if (ft_is_str_valid(str) != 1)
		return (0);
	return (1);
}

int	main(void)
{
	char	**test;
//	int	i = 0;

	test = malloc(7 * sizeof(char *));
	test[0] = "Le silence éternel de ces espaces infinis m’effraie\0";
	test[1] = "012345";
	test[2] = "5654";
	test[3] = "545";
	test[4] = "5443";
	test[5] = "46357";
	test[6] = NULL;
	
	printf ("Les resultat est : %d", ft_is_input_valid(test));
/*	while (i <= 5)
	{
		printf ("%s\n", test[i]);
		i++;
	}*/
	free (test);
	return (0);
}
