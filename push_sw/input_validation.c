/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:50:50 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/13 11:28:04 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if ((ft_atoi(src) > INT_MAX) || (ft_atoi(src) < INT_MIN))
		return (0);
	return (1);
}

static int	ft_is_repetition(char **str)
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

static int	ft_is_str_valid(char **str)
{
	int	i;

	i = 0;
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
