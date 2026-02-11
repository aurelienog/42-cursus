/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:09:03 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/11 14:02:43 by ppousser         ###   ########.fr       */
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
	stacks->b = NULL;
	return (stacks);
}
