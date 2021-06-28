/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:22:06 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/28 16:45:42 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_pa(t_vars *vars)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!vars->start_b)
		return (0);
	tmp_b = vars->start_b;
	vars->start_b = tmp_b->next;
	if (vars->start_a)
	{
		tmp_a = vars->start_a;
		vars->start_a = tmp_b;
		tmp_b->next = tmp_a;
	}
	else
	{
		vars->start_a = tmp_b;
		tmp_b->next = 0;
	}
	ft_putstr("pa\n");
	return (1);
}

int	f_pb(t_vars *vars)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!vars->start_a)
		return (0);
	tmp_a = vars->start_a;
	vars->start_a = tmp_a->next;
	if (vars->start_b)
	{
		tmp_b = vars->start_b;
		vars->start_b = tmp_a;
		tmp_a->next = tmp_b;
	}
	else
	{
		vars->start_b = tmp_a;
		tmp_a->next = 0;
	}
	ft_putstr("pb\n");
	return (1);
}
