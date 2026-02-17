/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:49:58 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/17 11:48:53 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	separate_bit(t_stacks *stacks, int size, int bit)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((stacks->a->index >> bit & 1) == 0)
			pb(stacks);
		else
			ra(stacks);
		i++;
	}	
}

int	count_max_bits(int size)
{
	int	max_bits;
	int	num_max;

	num_max = size - 1;
	max_bits = 0;
	while ((num_max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stacks *stacks, int size)
{
	int	max_bits;
	int	i;

	max_bits = count_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		separate_bit(stacks, size, i);
		while (stacks->b)
			pa(stacks);
		i++;
	}
}
