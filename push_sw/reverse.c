/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:13:36 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/04 11:36:16 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	reverse(&stacks->a);
	write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks)
{
	reverse(&stacks->b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks)
{
	reverse(&stacks->a);
	reverse(&stacks->b);
	write(1, "rrr\n", 4);
}
