/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:22:28 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/28 16:38:53 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_sa(t_vars *vars)
{
	t_stack	*tmp;
	t_stack	*tmp_first;

	if (!vars->start_a || !vars->start_a->next)
		return (0);
	tmp = vars->start_a->next->next;
	tmp_first = vars->start_a;
	vars->start_a = vars->start_a->next;
	vars->start_a->next = tmp_first;
	vars->start_a->next->next = tmp;
	ft_putstr("sa\n");
	return (1);
}

int	f_sb(t_vars *vars)
{
	t_stack	*tmp;
	t_stack	*tmp_first;

	if (!vars->start_b || !vars->start_b->next)
		return (0);
	tmp = vars->start_b->next->next;
	tmp_first = vars->start_b;
	vars->start_b = vars->start_b->next;
	vars->start_b->next = tmp_first;
	vars->start_b->next->next = tmp;
	ft_putstr("sb\n");
	return (1);
}

int	f_ss(t_vars *vars)
{
	t_stack	*tmp;
	t_stack	*tmp_first;
	int		ret;

	ret = 0;
	if (vars->start_a && vars->start_a->next)
	{
		tmp = vars->start_a->next->next;
		tmp_first = vars->start_a;
		vars->start_a = vars->start_a->next;
		vars->start_a->next = tmp_first;
		vars->start_a->next->next = tmp;
		ret = 1;
	}
	if (vars->start_b && vars->start_b->next)
	{
		tmp = vars->start_b->next->next;
		tmp_first = vars->start_b;
		vars->start_b = vars->start_b->next;
		vars->start_b->next = tmp_first;
		vars->start_b->next->next = tmp;
		ret = 1;
	}
	if (ret)
		ft_putstr("ss\n");
	return (ret);
}
