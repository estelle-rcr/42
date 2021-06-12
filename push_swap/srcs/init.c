/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:04:59 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/08 15:12:07 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_vars	*init_vars(void)
{
	t_vars	*vars;

	vars = NULL;
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == 0)
		return (NULL);
	ft_bzero(vars, sizeof(t_vars));
	vars->ops_list = (char *[12]){"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr", 0};
	return (vars);
}

t_stack	*add_new_stack(t_stack *first, int nb)
{
	t_stack	*stack;
	t_stack	*tmp;

	tmp = first;
	stack = NULL;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->nb = nb;
	stack->next = NULL;
	if (!first)
		first = stack;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = stack;
	}
	return (first);
}
