/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:35:38 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/15 18:26:53 by aunoguei         ###   ########.fr       */
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
		ra(stacks);
		sa(stacks);
	}
	else if (a > b && b < c && c < a)
		sa(stacks);
	else if (a > b && b < c && c > a)
	{
			sa(stacks);
			rra(stacks);
	}
	else if (a > b && b > c && c < a)
	{
		sa(stacks);
		rra(stacks);
	}
}
/*
static void	sort_five(t_stacks *stacks, int size)
{
	sort_three(stacks);
}
*/
void	adaptative_sort(t_stacks *stacks, int size)
{
	if (size < 2)
		return;
	else if (size == 2)
	{
		if (stacks->a->index > stacks->a->next->index)
			sa(stacks);
		return ;
	}
	else if (size == 3)
		sort_three(stacks);
/*	else if (size == 4 || size == 5)
		sort_five(stacks, size);
	else if ()
		insertion_sort()
	else if ()
		bucket_sort();
	else if ()
		radix_lsm();	
*/
}
