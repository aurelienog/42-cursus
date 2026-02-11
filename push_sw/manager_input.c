/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:31:34 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/11 16:19:19 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	extract_commands(char **input, t_command *commands)
{
	commands->bench = 0;
	commands->strategy = NULL;
	if (ft_is_int(input[1]) == 1)
		return ;
	if (ft_strncmp(input[1], "--bench", 7) == 0)
	{
		commands->bench = 1;
		if (ft_is_int(input[2]) != 1)
		{
			commands->strategy = ft_strdup(input[2]);
			if (!commands->strategy)
				return ;
		}
	}
	else
	{
		commands->strategy = ft_strdup(input[1]);
		if (ft_is_int(input[2]) != 1)
			commands->bench = 1;
	}
}

char	**extract_numbers(int *size, char **input)
{
	int	i;
	int	j;
	char	**res;

	i = 0;
	j = 0;
	while (i < 3 && ft_is_int(input[i]) != 1)
	{
		*size = *size - 1;
		i++;
	}
	res = malloc ((*size + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (j < *size)
	{
		res[j] = ft_strdup(input[i]);
		i++;
		j++;
	}
	return (res);
}
		

char	**manage_input(int argc, char **argv, int *size)
{
	char	**res_final;
	int		i;

	i = 0;
	res_final = NULL;
	res_final = (convert_input(argc, argv, size));
	if (!res_final)
		return (NULL);
	if (ft_is_input_valid(res_final) != 1)
	{
		while (i < *size)
		{
			free(res_final[i]);
			i++;
		}
		free(res_final);
		write (2, "Error\n", 6);
		res_final = NULL;
	}
	return (res_final);
}
