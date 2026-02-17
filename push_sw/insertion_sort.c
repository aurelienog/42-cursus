/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:19:19 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/17 12:57:17 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_max(t_stacks *stacks)
{
	t_numbers_list	*key;

	key = stacks->a;
	if (key->index > stacks->b->index)
		return (1);
	return (0);
}

static	int	count_rotations(t_stacks *stacks)
{
	t_numbers_list	*key;
	t_numbers_list	*current;
	int				count;

	key = stacks->a;
	current = stacks->b;
	count = 0;
	while (current->next)
	{
		if ((key->index < current->index)
			&& (key->index > current->next->index))
			return (count + 1);
		count++;
		current = current->next;
	}
	return (-1);
}

static void	rotate_b_to_place_key(t_stacks *stacks, int rotations)
{
	int		i;

	if (rotations == -1)
	{
		if (is_max(stacks))
			pb(stacks);
		else
		{
			pb(stacks);
			rb(stacks);
		}
	}
	else
	{
		i = 0;
		while (i < rotations)
		{
			rb(stacks);
			i++;
		}
		pb(stacks);
		while (rotations-- > 0)
			rrb(stacks);
	}
}

void	insertion_sort(t_stacks *stacks)
{
	int	rotations;
	int	i;

	pb(stacks);
	i = 0;
	while (stacks->a)
	{
		rotations = count_rotations(stacks);
		rotate_b_to_place_key(stacks, rotations);
		i++;
	}
	while (stacks->b)
		pa(stacks);
}
