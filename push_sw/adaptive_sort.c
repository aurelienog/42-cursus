/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:35:38 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/17 17:57:47 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->a->index;
	b = stacks->a->next->index;
	c = stacks->a->next->next->index;
	if (a < b && b > c && c < a)
		rra(stacks);
	else if (a < b && b > c && c > a)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (a > b && b < c && c < a)
		ra(stacks);
	else if (a > b && b < c && c > a)
		sa(stacks);
	else if (a > b && b > c && c < a)
	{
		sa(stacks);
		rra(stacks);
	}
}

static void	sort_five(t_stacks *stacks, int size)
{
	while (stacks->a)
	{
		if (stacks->a->index == 0)
		{
			pb(stacks);
			break ;
		}
		ra(stacks);
	}
	if (size != 4)
	{
		while (stacks->a)
		{
			if (stacks->a->index == 1)
			{
				pb(stacks);
				break ;
			}
			ra(stacks);
		}
	}
	sort_three(stacks);
	while (stacks->b)
		pa(stacks);
}

void	adaptive_sort(t_stacks *stacks, int size, float disorder)
{
	if (size < 2)
		return ;
	else if (size == 2)
	{
		if (stacks->a->index > stacks->a->next->index)
			sa(stacks);
		return ;
	}
	else if (size == 3)
		sort_three(stacks);
	else if (size == 4 || size == 5)
		sort_five(stacks, size);
	else if (disorder < 0.2)
		insertion_sort(stacks);
	else if (disorder < 0.5)
		bucket_sort(stacks, size);
	else
		radix_sort(stacks, size);
}
