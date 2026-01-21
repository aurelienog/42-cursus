/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:25:13 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/21 15:52:39 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
int     main(void)
{
        t_list  *list;
        t_list  *first;
	t_list  *second;
	t_list  *third;

        list = NULL;

	first = ft_lstnew("node 1\0");
	second = ft_lstnew("node 2\0");
	third = ft_lstnew("node 3\0");

        ft_lstadd_back(&list, first);
        ft_lstadd_back(&list, second);
        ft_lstadd_back(&list, third);
        ft_lstdelone(second, ???????????);

        printf("first : %s\n", first);
	if (second)
		printf("second : %s\n", second);
	else
		printf("nothing there\n");
	printf("third : %s\n", first);
        return (0);
}
*/
