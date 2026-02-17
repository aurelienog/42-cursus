/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:31:34 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/17 15:25:52 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	extract_commands(char *input, t_command *commands)
{
	commands->bench = 0;
	commands->strategy = NULL;
	if (ft_strncmp(input, "--bench", 7) == 0)
	{
		commands->bench = commands->bench + 1;
		if (commands->bench != 1)
			return (0);
	}
	else
	{
		if (commands->strategy != NULL)
			return (0);
		commands->strategy = ft_strdup(input);
	}
	return (1);
}

char	**extract_numbers(int *size, char **input)
{
	int	i;
	int	j;
	char	**res;

	i = 0;
	j = 0;
	while (input[i] != NULL && ft_is_str_int(input[i]) != 1)
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
		

char	**manage_input(int argc, char **argv, int *size, t_command *commands)
{
	char	**res_final;
	int		i;

	i = 0;
	res_final = NULL;
	res_final = (convert_input(argc, argv, size));
	if (!res_final)
		return (NULL);
	if (ft_is_input_valid(res_final, commands) == 0)
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
