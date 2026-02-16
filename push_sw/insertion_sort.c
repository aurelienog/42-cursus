/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:19:19 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/15 15:37:14 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_max(t_stacks *stacks)
{
	t_numbers_list	*node;
	t_numbers_list	*max;

	node = stacks->b;
	max = stacks->b;
	while (node)
	{
		if (node->index > max->index)
			max = node;
		node = node->next;
	}
	while (stacks->b != max)
		rb(stacks);
}
/*
static	int	count_rotations(t_stacks *stacks)
{
	t_numbers_list	*key;
	t_numbers_list	*current;
	t_numbers_list  *min;
	t_numbers_list  *max;
	int				count;

	key = stacks->a;
	current = stacks->b;
	min = current;
	max = current;
	count = 0;
	while (current)
	{
		if (current->index < min->index)
			min = current;
		if (current->index > max->index)
			max = current;
		current = current->next;
	}
	current = stacks->b;
	while (current->next)
	{
		if ((key->index < current->index)
			&& (key->index > current->next->index))
			return (count + 1);
		count++;
		current = current->next;
	}
	current = stacks->b;
	count = 0;
	if (key->index < min->index || key->index > max->index)
	{
		while(current)
		{
			if (current == max)
				return (count + 1);
			count++;
			current = current->next;
		}
	}
	return (0);
}
*/

static int count_rotations(t_stacks *stacks)
{
    t_numbers_list *current;
    int count = 0;
    int key = stacks->a->index;

    current = stacks->b;

    while (current->next)
    {
        // CASO NORMAL
        if (current->index > key
            && current->next->index < key)
            return (count + 1);

        // CASO SALTO (max → min)
        if (current->index < current->next->index)
        {
            if (key > current->index
                || key < current->next->index)
                return (count + 1);
        }

        current = current->next;
        count++;
    }

    return (0);
}


static void	rotate_b_to_place_key(t_stacks *stacks, int rotations)
{
	int		i;

	i = 0;
	while (i < rotations)
	{
		rb(stacks);
		i++;
	}
	pb(stacks);
}

void	insertion_sort(t_stacks *stacks, int size)
{
	int	rotations;
		
	pb(stacks);
	while (stacks->a && size--)
	{
		rotations = count_rotations(stacks);
		rotate_b_to_place_key(stacks, rotations);
	}
	rotate_to_max(stacks);
	while (stacks->b)
		pa(stacks);
}
