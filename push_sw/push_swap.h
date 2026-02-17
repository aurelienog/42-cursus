/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:01:24 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/17 17:26:01 by ppousser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

typedef struct t_command
{
	int		bench;
	char	*strategy;
}			t_command;

typedef struct s_numbers_list
{
	int						content;
	int						index;
	struct s_numbers_list	*next;
}			t_numbers_list;

typedef struct s_stack
{
	struct s_numbers_list	*a;
	struct s_numbers_list	*b;
}			t_stacks;



float			compute_disorder(int size, t_numbers_list *stack);
void			push_swap(int size, char **argv);
t_stacks		*init_stacks(int size, char **argv);
void			select_algorithm(t_stacks *stacks, int size, t_command cmds);
/* ************************************************************************** */
/*                             WRAPPERS FUNCTIONS                             */
/* ************************************************************************** */

void			sa(t_stacks *stacks);
void			sb(t_stacks *stacks);
void			ss(t_stacks *stacks);
void			pa(t_stacks *stacks);
void			pb(t_stacks *stacks);
void			ra(t_stacks *stacks);
void			rb(t_stacks *stacks);
void			rr(t_stacks *stacks);
void			rra(t_stacks *stacks);
void			rrb(t_stacks *stacks);
void			rrr(t_stacks *stacks);

/* ************************************************************************** */
/*                             OPERATIONS FUNCTIONS                           */
/* ************************************************************************** */

void			bucket_sort(t_stacks *stacks, int size);
void			insertion_sort(t_stacks *stack);
void			radix_sort(t_stacks *stacks, int size);
void			adaptive_sort(t_stacks *stacks, int size, float disorder);
void			bubblesort(int *numbers, int size);
void			quicksort(int *numbers, int low, int high);

/* ************************************************************************** */
/*                             STRINGS FUNCTIONS                              */
/* ************************************************************************** */



int				ft_is_input_valid(char **str, t_command *commands);
int				ft_is_str_int(char *src);

/* ************************************************************************** */
/*                              MEMORY FUNCTIONS                              */
/* ************************************************************************** */

char			**convert_input(int size, char **argv, int *size_final);
char			**manage_input(int argc, char **argv, int *size, t_command *commands);
char			**extract_numbers(int *size, char **input);
int			extract_commands(char *input, t_command *commands);
void			free_input(char **input, int size, t_command commands);

/* ************************************************************************** */
/*                             LIST FUNCTIONS                                 */
/* ************************************************************************** */
void			swap(t_numbers_list **stack);
void			push(t_numbers_list **src, t_numbers_list **dest);
void			rotate(t_numbers_list **stack);
void			reverse(t_numbers_list **stack);
void			clear_lst_numbers(t_numbers_list **lst);
void			numbers_lstadd_front(t_numbers_list **lst, t_numbers_list *new);
void			numbers_lstadd_back(t_numbers_list **lst, t_numbers_list *new);
t_numbers_list	*numbers_lstnew(int content);
t_numbers_list	*numbers_lstlast(t_numbers_list *lst);
#endif
