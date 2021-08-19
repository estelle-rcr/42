/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:40:33 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/08 14:17:22 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*ptr;

	if (!lst || !f)
		return (NULL);
	ptr = ft_lstnew(f(lst->content));
	if (!ptr)
		return (NULL);
	lst2 = ptr;
	while (lst->next)
	{
		lst = lst->next;
		ptr->next = ft_lstnew(f(lst->content));
		if (!ptr->next)
		{
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ptr = ptr->next;
	}
	ptr->next = NULL;
	return (lst2);
}
