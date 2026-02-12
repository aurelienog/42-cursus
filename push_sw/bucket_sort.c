/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:02:19 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/12 15:35:46 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	square_root(int	nb)
{
	int	i;

	i = 1;
	while ((i * i) <= nb)
		i++;
	return (i - 1);
}


static void	rotate_a_push_b(t_stacks *stacks, int MIN, int bucket_size, int i)
{
	t_numbers_list	*start;
	int	range_min;
	int	range_max;

	range_min = MIN + (bucket_size * i);
	range_max = MIN + (bucket_size * (i + 1));
	while (stacks->a->content >= range_min
			&& stacks->a->content < range_max)
		pb(stacks);
	start = stacks->a;
	ra(stacks);
	while (stacks->a != start)
	{
		if (stacks->a->content >= range_min
				&& stacks->a->content < range_max)
			pb(stacks);
		else
			ra(stacks);
	}
}


static void	create_buckets(t_stacks *stacks, int MIN, int bucket_size)
{
	int	i;

	i = 0;
	while (i < bucket_size)
	{
		rotate_a_push_b(stacks, MIN, bucket_size, i);
		i++;
	}
	while (stacks->b != NULL)
		pa(stacks);
}
void	organize_buckets(t_stacks *stacks, int MIN, int bucket_size)
{
	t_numbers_list	*temp;
	int	count;

	temp = stack->a;
	count = 0;
	while (temp->content < (range_max))
	{
		count++;
		temp = temp->next;
	}
}

void	sort_bucket(t_stacks *stacks)
{
	int	bucket_size;
	int	MAX;
	int	MIN;
	t_numbers_list	*comparaison;

	
	MAX = stacks->a->content;
	MIN = stacks->a->content;
	comparaison = stacks->a->next;
	while(comparaison != NULL)
	{
		if (MAX < comparaison->content)
			MAX = comparaison->content;
		if (MIN > comparaison->content)
			MIN = comparaison->content;
		comparaison = comparaison->next;
	}
	bucket_size = square_root(MAX - MIN);
	create_buckets(stacks, MIN, bucket_size);
	organize_buckets(stacks, MIN, bucket_size);
}
		
