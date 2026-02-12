/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:19:19 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/12 12:04:21 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_b_to_place_key(t_stacks *stacks, t_numbers_list *key)
{
	int				rotation_count;
	t_numbers_list	*start;

	rotation_count = 0;
	start = stacks->b;
	while (start && (key->content < stacks->b->content))
	{
		if (stacks->b->next == NULL || stacks->b->next == start)
		{
			rb(stacks);
			rotation_count++;
			start = NULL;
		}
		else
		{
			rotation_count++;
			rb(stacks);
		}
	}
	pb(stacks);
	while (rotation_count > 0)
	{
		rrb(stacks);
		rotation_count--;
	}
}

static void	init_stack_b(t_stacks *stacks)
{
	if (stacks->a->content > stacks->a->next->content)
		sa(stacks);
	pb(stacks);
	pb(stacks);
}

void	insertion_sort(t_stacks *stacks)
{
	t_numbers_list	*key;

	init_stack_b(stacks);
	while (stacks->a)
	{
		key = stacks->a;
		if (key->content > stacks->b->content)
			pb(stacks);
		else
			rotate_b_to_place_key(stacks, key);
	}
	while (stacks->b)
		pa(stacks);
}
