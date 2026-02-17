/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:47:35 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/17 16:23:56 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	select_algorithm(t_stacks *stacks, int size, t_command cmds)
{
	float	disorder;

	disorder = compute_disorder(size, stacks->a);
	if (disorder == 0)
		return ;
	if (cmds.strategy == NULL || ft_strlen(cmds.strategy) == 10)
		adaptive_sort(stacks, size, disorder);
	else
	{
		if (ft_strlen(cmds.strategy) == 9)
			radix_sort(stacks, size);
		else if (ft_strlen(cmds.strategy) == 8)
		{
			if (ft_strncmp(cmds.strategy, "--simple", 8) == 0)
				insertion_sort(stacks);
			else
				bucket_sort(stacks, size);
		}
	}
}
