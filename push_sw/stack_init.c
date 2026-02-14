/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:09:03 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/14 16:53:14 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_lst_numbers(t_numbers_list **lst)
{
	t_numbers_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
/*
static int	assign_index(t_numbers_list *stack->a, char **numbers, int size)
{
	int	*ordered;
	int	i;
	int	*min;
	int	*max;

	ordered = copy_to_array(numbers, size);
	if (!ordered)
		return (0);
	if (size < 100)
		bubblesort(ordered);
	else
	{
		//definir min & max
		find_extreme_values(ordered);
		quicksort(ordered, min, max);
	//assign index
	free(ordered);
	return (1);
}
*/
static t_numbers_list	*init_stack_a(int size, char **numbers)
{
	int				i;
	int				num;
	t_numbers_list	*node;
	t_numbers_list	*stack_a;

	i = 0;
	stack_a = NULL;
	node = NULL;
	while (i < size)
	{
		num = ft_atoi(numbers[i]);
		node = numbers_lstnew(num);
		if (!node)
		{
			clear_lst_numbers(&stack_a);
			return (NULL);
		}
		numbers_lstadd_back(&stack_a, node);
		i++;
	}
	return (stack_a);
}

t_stacks	*init_stacks(int size, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(1 * sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = init_stack_a(size, argv);
	if (!stacks->a)
	{
		free(stacks);
		return (NULL);
	}
	/*
	//assign_index(stacks->a, size);
	if (!assign_index(stacks->a, size))
	{
		free(stacks);
		return (NULL);
	}*/
	stacks->b = NULL;
	return (stacks);
}
