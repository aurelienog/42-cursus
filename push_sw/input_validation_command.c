/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:32:47 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/04 14:39:59 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"

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

int	ft_is_command_valid(char *str1, char *str2)
{
	if ((ft_strncmp(str1, "--bench", 7) != 0) || ft_strlen(str1) != 7)
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
}
