/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:41:26 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/16 14:50:58 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static int	square_root(long unsigned nb)
{
	long unsigned	i;

	i = 1;
	while ((i * i) <= nb)
		i++;
	return (i - 1);
}

int	is_bucket_needed(t_numbers_list *stacksa, int min_bucket, int max_bucket, int size)
{
	t_numbers_list	*temp;
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (stacksa == NULL)
		return (0);
	temp = stacksa;
	while (temp != NULL && i < size)
	{
		if (temp->index >= min_bucket && temp->index < max_bucket)
			count++;
		temp = temp->next;
		i++;
	}
	return (count);
}

void	create_next_bucket(t_stacks *stacks, int bucket_size, int i, int size)
{
	int	max_bucket;
	int	min_bucket;
	int	count;

	min_bucket = bucket_size * i;
	max_bucket = bucket_size * (i + 1);
	count = is_bucket_needed(stacks->a, min_bucket, max_bucket, size);
	while (count > 0)
	{
		if (stacks->a->index >= min_bucket && stacks->a->index < max_bucket)
		{
			pb(stacks);
			count--;
		}
		else
			ra(stacks);
	}
}

/*void	place_maximum(t_stacks *stacks, int size)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (stacks->b->index != (size - 1))
	{
		stacks->b = stacks->b->next;
		count++;
	}
	pa(stacks);
	while (i < count)
	{
		rrb(stacks);
		i++;
	}
}*/

void	sort_buckets(t_stacks *stacks)
{
	int	count_ra;

	count_ra = 0;
//	place_maximum(stacks, size);
	pa(stacks);
	while (stacks->b)
	{
		if (stacks->a->index > stacks->b->index)
			pa(stacks);
		else
		{
			while (stacks->a->index < stacks->b->index)
			{
				ra(stacks);
				count_ra++;
			}
			pa(stacks);
			while (count_ra > 0)
			{
				rra(stacks);
				count_ra--;
			}
		}
	}
}
static void	create_buckets(t_stacks *stacks, int bucket_size, int size)
{
	int	i;

	i = 0;
	while (i < bucket_size - 1)
	{
		create_next_bucket(stacks, bucket_size, i, size);
		i++;
	}
	while (stacks->a)
	{
		if (stacks->a->index == size - 1)
		{
			if(stacks->a->next != NULL)
			{
				ra(stacks);
			}
			else
				return ;
		}
		pb(stacks);
	}
}

void	bucket_sort(t_stacks *stacks, int size)
{
	int	bucket_size;

	bucket_size = square_root(size);
	create_buckets(stacks, bucket_size, size);
	sort_buckets(stacks);
}
