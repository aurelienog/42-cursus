/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aunoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:58:11 by aunoguei          #+#    #+#             */
/*   Updated: 2026/01/20 13:33:17 by aunoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	if (!content)
		return (NULL);
	ptr = ft_calloc(1, sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
