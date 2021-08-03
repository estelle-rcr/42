/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:22:13 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/28 19:33:55 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_rra(t_vars *vars)
{
	t_stack	*tmp_a;
	t_stack	*last;
	t_stack	*start;

	if (!vars->start_a || !vars->start_a->next)
		return (0);
	tmp_a = vars->start_a;
	start = vars->start_a;
	while (tmp_a->next->next)
		tmp_a = tmp_a->next;
	last = tmp_a->next;
	tmp_a->next = 0;
	vars->start_a = last;
	last->next = start;
	return (1);
}

int	f_rrb(t_vars *vars)
{
	t_stack	*tmp_b;
	t_stack	*last;
	t_stack	*start;

	if (!vars->start_b || !vars->start_b->next)
		return (0);
	tmp_b = vars->start_b;
	start = vars->start_b;
	while (tmp_b->next->next)
		tmp_b = tmp_b->next;
	last = tmp_b->next;
	tmp_b->next = 0;
	vars->start_b = last;
	last->next = start;
	return (1);
}

int	f_rrr(t_vars *vars)
{
	int		ret;

	ret = 0;
	if (f_rra(vars))
		ret = 1;
	if (f_rrb(vars))
		ret = 1;
	return (ret);
}
