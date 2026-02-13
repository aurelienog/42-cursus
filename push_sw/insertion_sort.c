/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:19:19 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/13 15:19:32 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	sort_three(t_stacks *stacks)
{
	if (!stacks->a || !stacks->a->next)
		return ;
	if (stacks->a->content > stacks->a->next->content)
		sa(stacks);
	if (stacks->a->next->next)
	{
		if (stacks->a->next->next->content < stacks->a->next->content)
		{
			ra(stacks);
			sa(stacks);
			rra(stacks);
		}
		if (stacks->a->content > stacks->a->next->content)
			sa(stacks);
	}
}

static	void	rotate_to_max(t_stacks *stacks)
{
	t_numbers_list	*node;
	t_numbers_list	*max;

	node = stacks->b;
	max = stacks->b;
	while (node)
	{
		if (node->content > max->content)
			max = node;
		node = node->next;
	}
	while (stacks->b != max)
		rb(stacks);
}

static	int	count_rotations(t_stacks *stacks)
{
	t_numbers_list  *key;
	t_numbers_list	*current;
	int	count;

	key = stacks->a;
	current = stacks->b;
	count = 1;
	while (current->next)
	{
		if ((key->content < current->content)
				&& (key->content > current->next->content))
			return (count);
		count++;
		current = current->next;
	}
	ft_printf("extrem");
	return (-1);
}

static void	rotate_b_to_place_key(t_stacks *stacks, int rotations)
{
	int		i;

	if (rotations == -1)
	{
		rotate_to_max(stacks);
		if (stacks->a->content > stacks->b->content)
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
	}
}

void	insertion_sort(t_stacks *stacks, int size)
{
	int		rotations;

	if (size <= 3)
    		sort_three(stacks);
	else
    	{
		pb(stacks);
		while (stacks->a)
		{
			rotations = count_rotations(stacks);
			rotate_b_to_place_key(stacks, rotations);
		}
		while (stacks->b)
			pa(stacks);
	}
}
