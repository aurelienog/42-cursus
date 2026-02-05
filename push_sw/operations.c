/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:00:24 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/05 09:42:02 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	swap(&stacks->a);
	write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	swap(&stacks->b);
	write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks)
{
	swap(&stacks->a);
	swap(&stacks->b);
	write(1, "ss\n", 3);
}

void	pa(t_stacks *stacks)
{
	push(&stacks->b, &stacks->a);
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	push(&stacks->a, &stacks->b);
	write(1, "pb\n", 3);
}
