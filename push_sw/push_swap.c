/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:49:34 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/04 17:43:33 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	push_swap(int size, char **argv)
{
	t_stacks	*stacks;
	t_list		*temp;
	//struc para opciones?
	int	i;
	stacks = init_stacks(size, argv);
	temp = printf("",)
	if (!stacks)
		return ;
	i = 0;
	while (i < size)
	{
		printf("%d\n", temp->content);
		temp = temp->next;
		i++;
	}
	ft_lstclear(&stacks->a);
	ft_lstclear(&stacks->b);
	free(stacks);
}

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
}
