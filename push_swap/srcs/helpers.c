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

void	find_max(t_vars *vars)
{
	t_stack	*tmp;
	int		pos;

	tmp = vars->start_a;
	pos = 0;
	vars->max = vars->start_a->nb;
	vars->pos_max = vars->len_a;
	while (tmp->next)
	{
		if (tmp->nb > vars->max)
		{
			vars->max = tmp->nb;
			vars->pos_max = vars->len_a - pos; 
		}
		pos++;
		tmp = tmp->next;
	}
	if (tmp->nb > vars->max)
	{
		vars->max = tmp->nb;
		vars->pos_max = vars->len_a - pos; 
	}
}

void	find_min(t_vars *vars)
{
	t_stack	*tmp;
	int		pos;

	tmp = vars->start_a;
	pos = 0;
	vars->min = vars->start_a->nb;
	vars->pos_min = vars->len_a;
	while (tmp->next)
	{
		if (tmp->nb < vars->min)
		{
			vars->min = tmp->nb;
			vars->pos_min = vars->len_a - pos; 
		}
		pos++;
		tmp = tmp->next;
	}
	if (tmp->nb < vars->min)
	{
		vars->min = tmp->nb;
		vars->pos_min = vars->len_a - pos; 
	}
}

void	do_op(t_vars *vars, int(*f)(t_vars *), int op)
{
	if ((*f)(vars))
		vars->ops = add_new_op(vars->ops, op);
}