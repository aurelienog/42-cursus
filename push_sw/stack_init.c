/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:09:03 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/03 17:27:39 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}

static int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i++] - '0';
	}
	return (number * sign);
}

t_list	*init_stack_a(char **numbers)
{
	size_t	i;
	int		num;
	t_list	*node;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	node = NULL;
	while (numbers[i])
	{
		num = ft_atoi(*numbers[i]);
		node = ft_lstnew(num);
		if (!node)
		{
			ft_lstclear(stack_a);
			return (NULL);
		}
		ft_lstadd_back(stack_a, node);
		i++;
	}
	return (stack_a);
}

t_stacks	*init_stacks(char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(1 * sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a =  init_stack_a(argv);
	stacks->b = NULL;
	return (stacks);
}
