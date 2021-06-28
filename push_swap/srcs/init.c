/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:04:59 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/28 18:57:11 by erecuero         ###   ########.fr       */
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
	return (vars);
}

t_stack	*add_new_item(t_stack *first, int nb)
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

t_ops	*add_new_op(t_ops *first, int nb)
{
	t_ops	*op;
	t_ops	*tmp;

	tmp = first;
	op = NULL;
	op = (t_ops *)malloc(sizeof(t_ops));
	if (op == NULL)
		return (NULL);
	op->nb = nb;
	op->next = NULL;
	if (!first)
		first = op;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = op;
	}
	return (first);
}
