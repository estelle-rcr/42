/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:40:33 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/16 12:25:25 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*ptr;

	if (!lst || !f)
		return (NULL);
	if (!(ptr = ft_lstnew(f(lst->content))))
		return (NULL);
	lst2 = ptr;
	while (lst->next)
	{
		lst = lst->next;
		if (!(ptr->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ptr = ptr->next;
	}
	ptr->next = NULL;
	return (lst2);
}
