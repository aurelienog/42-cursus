/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:32:57 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 08:45:16 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

/*
int     main(void)
{
        t_list  *list;
        t_list  *last;


        list = NULL;
        ft_lstadd_back(&list, ft_lstnew("node 1\0"));
        ft_lstadd_back(&list, ft_lstnew("node 2\0"));
        ft_lstadd_back(&list, ft_lstnew("node 3\0"));
        last = ft_lstlast(list);
        if (last && list)
                printf("last : %s\n", (char *)last->content);
	ft_lstclear(&list, ?????);
	if (list)
		printf("after cleaning : %s\n", (char *)list->content);
	else
		printf("nothing here");
        return (0);
}
*/
