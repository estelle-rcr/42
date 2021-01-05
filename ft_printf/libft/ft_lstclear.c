/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:40:07 by erecuero          #+#    #+#             */
/*   Updated: 2020/11/26 12:40:08 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (lst && *lst)
	{
		while (*lst)
		{
			next = (*lst)->next;
			del((*lst)->content);
			free((*lst));
			(*lst) = next;
		}
		(*lst) = NULL;
	}
	return ;
}
