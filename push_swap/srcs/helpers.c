/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:06:57 by erecuero          #+#    #+#             */
/*   Updated: 2021/07/08 20:17:29 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max(t_vars *vars, t_stack *stack)
{
	t_stack	*tmp;
	int		pos;

	if (!stack)
		return;
	tmp = stack;
	pos = 0;
	vars->pos_max = 0;
	vars->max = stack->nb;
	while (tmp->next)
	{
		if (tmp->nb > vars->max)
		{
			vars->max = tmp->nb;
			vars->pos_max = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (tmp->nb > vars->max)
	{
		vars->max = tmp->nb;
		vars->pos_max = pos;
	}
}

void	find_min(t_vars *vars, t_stack *stack)
{
	t_stack	*tmp;
	int		pos;

	if (!stack)
		return;
	tmp = stack;
	pos = 0;
	vars->min = stack->nb;
	vars->pos_min = 0;
	while (tmp->next)
	{
		if (tmp->nb < vars->min)
		{
			vars->min = tmp->nb;
			vars->pos_min = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (tmp->nb < vars->min)
	{
		vars->min = tmp->nb;
		vars->pos_min = pos;
	}
}

int	get_last_nb(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->nb);
}

void	do_op(t_vars *vars, int(*f)(t_vars *), int op)
{
	if ((*f)(vars))
		vars->ops = add_new_op(vars->ops, op);
}
