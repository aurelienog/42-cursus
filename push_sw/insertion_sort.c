/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:19:19 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/14 14:15:54 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static	void	sort_three(t_stacks *stacks)
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
*/
static int	is_max(t_stacks *stacks)
{
	t_numbers_list	*key;

	key = stacks->a;
	if (key->content > stacks->b->content)
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
		if ((key->content < current->content)
			&& (key->content > current->next->content))
			return (count + 1);
		count++;
		current = current->next;
	}
	return (-1);
}

static void	rotate_b_to_place_key(t_stacks *stacks, int rotations)
{
	int		i;
	int		reverse;

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
		reverse = rotations;
		while (i < rotations)
		{
			rb(stacks);
			i++;
		}
		pb(stacks);
		while (reverse > 0)
		{
			rrb(stacks);
			reverse--;
		}
	}
}

void	insertion_sort(t_stacks *stacks, int size)
{
	int	rotations;
	int	i;
		
	pb(stacks);
	i = 0;
	while (stacks->a && size)
	{
		rotations = count_rotations(stacks);
		rotate_b_to_place_key(stacks, rotations);
		i++;
	}
	while (stacks->b)
		pa(stacks);
}
