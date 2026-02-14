/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppousser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:02:19 by ppousser          #+#    #+#             */
/*   Updated: 2026/02/13 17:28:44 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	square_root(long unsigned nb)
{
	long unsigned	i;

	i = 1;
	while ((i * i) <= nb)
		i++;
	return (i - 1);
}

static int	is_bucket_empty(t_numbers_list *stacks_a, int bucket_min, int bucket_max, int size)
{
	int			i;
	t_numbers_list	*temp;

	i = 0;
	temp = stacks_a;
	while (i < size && temp->next != NULL)
	{
		if (temp->content >= bucket_min && temp->content < bucket_max)
			return (1);
		i++;
		temp = temp->next;
	}
	return (0);
}

static void	rotate_a_push_b(t_stacks *stacks, int MIN, int bucket_size, int i, int size)
{
//	t_numbers_list	*start;
	int	range_min;
	int	range_max;
	int	j;

	j = 0;
	range_min = MIN + (bucket_size * i);
	range_max = MIN + (bucket_size * (i + 1));
	if (is_bucket_empty(stacks->a, range_min, range_max, size) != 1)
		return ;
	while (stacks->a->content >= range_min
			&& stacks->a->content < range_max)
	{
		j++;
		pb(stacks);
	}
//	start = stacks->a;
	ra(stacks);
	j++;
	while (j <= size)
	{
		if (stacks->a->content >= range_min
				&& stacks->a->content < range_max)
			pb(stacks);
		else
			ra(stacks);
		j++;
	}
}

static void	organize_buckets(t_stacks *stacks, int MIN, int bucket_range, int i)
{
	int	size_bucket;
	t_numbers_list	*temp;
	int	max_bucket;
	int	min_bucket;

	size_bucket = 0;
	min_bucket = MIN + (bucket_range * i);
	max_bucket = MIN + (bucket_range * (i + 1));
	temp = stacks->a;
	while (temp != NULL && temp->content < min_bucket)
	{
		temp = temp->next;
	}
	while (temp != NULL &&  temp->content < max_bucket)
	{
		size_bucket++;
		temp = temp->next;
	}
	if (size_bucket == 0 || size_bucket == 1)
		return;
	insertion_sort(stacks, size_bucket);
}

static void	create_buckets(t_stacks *stacks, int MIN, int bucket_size, int size)
{
	int	i;

	i = 0;
	while (i <= bucket_size)
	{
		rotate_a_push_b(stacks, MIN, bucket_size, i, size);
		i++;
	}
	while (stacks->b != NULL)
		pa(stacks);
	i = 0;
	while (i <= bucket_size + 1)
	{
		organize_buckets(stacks, MIN, bucket_size, i);
		i++;
	}
	if (stacks->a->content > stacks->a->next->content)
		ra(stacks);
}


void	sort_bucket(t_stacks *stacks, int size)
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
	create_buckets(stacks, MIN, bucket_size, size);
}	
