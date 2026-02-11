/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:19:19 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/11 18:31:25 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stacks *stacks)
{
	t_numbers_list	*key;
	int	i;
	
	i = 0;
	key = stacks->a->next;
	while (i < 5 && key)
	{
		while (key && (key->content > stacks->a->content))	
		{
			pb(stacks);
		}
		rra(stacks);
		while((stacks)->b)
		{
			pa(stacks);
	
		}
		key = (stacks)->a->next;
		i++;
	}
}
/*
int	main(void)
{
	t_list	*temp;

	insertion_sort();
	temp = *stack_a;
	while (temp->next)
	{
		printf("%d ", temp->content[i]);
		temp = temp->next;
	}
	return ();
}*/
