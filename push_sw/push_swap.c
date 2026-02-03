/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <aunoguei@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:49:34 by aunoguei          #+#    #+#             */
/*   Updated: 2026/02/03 17:22:03 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	push_swap(char **argv)
{
	t_stacks	*stacks;
	//function que crea puntero a struct con las opciones?
	//function que devuelve un ptr al primer numero para pasarlo a init
	stacks = init_stacks(argv);
	ft_lstclear(stacks->a);
	ft_lstclear(stacks->b);
}
