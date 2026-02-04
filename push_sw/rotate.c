/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:09:36 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/04 11:36:00 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	rotate(&stacks->a);
	write(1, "ra\n", 3);
}

void	rb(t_stacks *stacks)
{
	rotate(&stacks->b);
	write(1, "rb\n", 3);
}

void	rr(t_stacks *stacks)
{
	rotate(&stacks->a);
	rotate(&stacks->b);
	write(1, "rr\n", 3);
}
