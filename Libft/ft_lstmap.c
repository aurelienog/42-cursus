/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:22:48 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/22 09:06:50 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		content = f(lst->content);
		newnode = ft_lstnew(content);
		if (!newnode)
		{
			del(content);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
/*
int     main(void)
{
        t_list  *list;
        t_list  *new;


        list = NULL;
        ft_lstadd_back(&list, ft_lstnew("node 1\0"));
        ft_lstadd_back(&list, ft_lstnew("node 2\0"));
        ft_lstadd_back(&list, ft_lstnew("node 3\0"));
	new = ft_lstmap(?????????????);
        return (0);
}
*/
