/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:49:34 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/17 17:22:56 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(int size, t_numbers_list *stack)
{
	float			mistakes;
	float			total_pairs;
	int				i;
	int				j;
	t_numbers_list	*node;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		node = stack->next;
		while (j < size)
		{
			total_pairs++;
			if (stack->content > node->content)
				mistakes++;
			node = node->next;
			j++;
		}
		stack = stack->next;
		i++;
	}
	return (mistakes / total_pairs);
}
#include <stdio.h>
void	push_swap(int argc, char **argv)
{
	t_stacks	*stacks;
	char		**input;
	t_command	commands;
	char		**numbers;
	int			size;

	size = -1;
	commands.strategy = NULL;
	input = manage_input(argc, argv, &size, &commands);
	if (!input)
		return ;
	numbers = extract_numbers(&size, input);
	stacks = init_stacks(size, numbers);
	free_input(input, size, commands);
	if (!stacks)
	{
		free(commands.strategy);
		return ;
	}
	select_algorithm(stacks, size, commands);
//	select_algorythm(stacks, size, commands);
	free(commands.strategy);
	clear_lst_numbers(&stacks->a);
	free(stacks);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**ptr;
	int	size;

	size = 5;
	ptr = malloc(size * sizeof(char *));
	if (!ptr)
		return (1);
	ptr[0] = "5646646";
	ptr[1] = "-132156";
	ptr[2] = "0";
	ptr[3] = "-2147483648";
	ptr[4] = "2147483647";
	push_swap(size, ptr);
	free(ptr);
	printf("end");
	return (0);
}*/
