/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:38:04 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/03 16:13:48 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int	compute_disorder(char *stack)
{
	int	mistakes;
	int	total_pairs;
	t_list	*node;

	node = stack->next;
	mistakes = 0;
	total_pairs = 0;
	while (stack)
	{
		while (node)
		{
			if (stack->content > node->content)
				mistakes++;
			total_pairs++;
			node = stack->next;
		}
		stack = stack->next;
	}
	return (mistakes / total_pairs);
}
*/
void	swap(t_list *stack)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = stack;
	temp_b = stack->next;
	stack->next = temp_a;
	temp_b->next = temp_b;
}

void	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	temp = (*src)->next;
	ft_lstadd_front(dest, *src);
	*src = temp;
}

void	rotate(t_list **stack)
{
	t_list	*last;
	t_list	*new_first;

	last = ft_lstlast(*stack);
	new_first = (*stack)->next;
	(*stack)->next = NULL;
	last->next = *stack;
	*stack = new_first;
}

void	reverse(t_list **stack)
{
	int		size;
	int		i;
	t_list	*last;
	t_list	*before_last;
	t_list	*ref;

	i = 0;
	ref = *stack;
	size = ft_lstsize(*stack);
	while (i < size - 2)
	{
		*stack = (*stack)->next;
		i++;
	}
	before_last = *stack;
	last = (*stack)->next;
	before_last->next = NULL;
	ft_lstadd_front(stack, last);
	last->next = ref;
}
/*
#include <stdio.h>
int     main(void)
{
        t_list  *stack_a;
	t_list	*stack_b;
        t_list  *nodea;
        t_list  *nodemiddle;
        t_list  *nodeb;
	t_list	*node1;
	t_list  *node2;
	t_list  *node3;

        stack_a = NULL;
	stack_b = NULL;
        nodea = ft_lstnew("je suis 3a\0");
        ft_lstadd_front(&stack_a, nodea);
        nodemiddle = ft_lstnew("je suis 2a\0");
        ft_lstadd_front(&stack_a, nodemiddle);
        nodeb = ft_lstnew("je suis 1a\0");
        ft_lstadd_front(&stack_a, nodeb);
	node1 = ft_lstnew("je suis 3b\0");
        ft_lstadd_front(&stack_b, node1);
        node2 = ft_lstnew("je suis 2b\0");
        ft_lstadd_front(&stack_b, node2);
        node3 = ft_lstnew("je suis 1b\0");
        ft_lstadd_front(&stack_b, node3);
	push(&stack_a, &stack_b);
	printf("stack a\n");
        while (stack_a)
        {
                printf("Before %s ", (char *)stack_a->content);
                stack_a = stack_a->next;
        }
        printf("\n");
	printf("stack b\n");
        while (stack_b)
        {
                printf("after %s ", (char *)stack_b->content);
                stack_b = stack_b->next;
        }
        return (0);
}
*/
/*
#include <stdio.h>
int     main(void)
{
        t_list  *list;
	t_list *ref;
        t_list  *nodea;
        t_list  *nodemiddle;
        t_list  *nodeb;

	
        list = NULL;
        nodea = ft_lstnew("je suis 3\0");
        ft_lstadd_front(&list, nodea);
        nodemiddle = ft_lstnew("je suis 2\0");
        ft_lstadd_front(&list, nodemiddle);
        nodeb = ft_lstnew("je suis 1\0");
        ft_lstadd_front(&list, nodeb);
	ref = list;
	while (list)
	{
		printf("Before %s ", (char *)list->content);
		list = list->next;
	}
	printf("\n");
	rotate(&ref);
	while (ref)
        {
                printf("after %s ", (char *)ref->content);
                ref = ref->next;
        }
        return (0);
}
*/
/*
MAIN PARA ROTATE 
#include <stdio.h>
int	main(void)
{
	t_list	*list;
	t_list	*nodea;
	t_list	*nodemiddle;
	t_list	*nodeb;
	t_list	*last;

	list = NULL;
	nodea = ft_lstnew("je suis 3");
	ft_lstadd_front(&list, nodea);
	nodemiddle = ft_lstnew("je suis 2");
	ft_lstadd_front(&list, nodemiddle);
	nodeb = ft_lstnew("je suis 1");
	ft_lstadd_front(&list, nodeb);
	last = ft_lstlast(list);
	printf("first antes %s\n", (char *)list->content);
	printf("last antes %s\n", (char *)last->content);
	//rotate(&list);
	//reverse(&list);
	last = ft_lstlast(list);
	printf("first despues %s\n", (char *)list->content);
	printf("last despues %s\n", (char *)last->content);
	return (0);
}*/
