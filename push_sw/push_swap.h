/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:01:24 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/04 15:20:59 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}			t_list;

typedef struct s_stack
{
	struct s_list	*a;
	struct s_list	*b;
}			t_stacks;

void	push_swap(int size, char **argv);

t_stacks	*init_stacks(int size, char **argv);
/* ************************************************************************** */
/*                             LIST FUNCTIONS                                 */
/* ************************************************************************** */
void	swap(t_list **stack);
void	push(t_list **src, t_list **dest);
void	rotate(t_list **stack);
void	reverse(t_list **stack);

void	ft_lstclear(t_list **lst);

/** ft_lstnew - Allocates memory (using malloc(3)) and returns
a new node.
 * @param - content: The content to store in the new node
 * @return - a pointer to the new node
 * @note - content can be NULL
 */
t_list	*ft_lstnew(int content);

/** ft_lstadd_front - Adds the node ’new’ at the beginning of the list
 * @param - lst: The address of a pointer to the first node of a list
 * new: The address of a pointer to the node to be added
 * @return - none
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/** ft_lstadd_back - Adds the node ’new’ at the end of the list
 * @param - lst: The address of a pointer to the first node of a list
 * new: The address of a pointer to the node to be added
 * @return - none
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/** ft_lstlast - Returns the last node of the list
 * @param - lst: The beginning of the list
 * @return - last node of the list
 */
t_list	*ft_lstlast(t_list *lst);
#endif
