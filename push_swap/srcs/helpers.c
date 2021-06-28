/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:06:57 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/28 19:14:36 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack_nb(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (stack)
	{
		tmp = stack;
		while (tmp->next)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (++i);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*cmp;

	if (stack)
	{
		tmp = stack;
		while (tmp->next)
		{
			cmp = tmp->next;
			while (cmp)
			{
				if (tmp->nb > cmp->nb)
					return (0);
				cmp = cmp->next;
			}
			tmp = tmp->next;
		}
	}
	return (1);
}
