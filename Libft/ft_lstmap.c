/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:22:48 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/20 15:36:30 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*start;

	if (!lst || !f || !del)
		return (NULL);
	newlist = ft_calloc(1, sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist = lst;
	start = lst;
	while (newlist)
	{
		newlist->content = f(newlist->content);
		newlist = newlist->next;
	}
	newlist = start;
	return (newlist);
}
