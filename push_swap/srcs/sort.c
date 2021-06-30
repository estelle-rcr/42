/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:19:27 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/30 12:06:24 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_input(t_vars *vars)
{
	vars->len_a = vars->nb_input;
	if (vars->nb_input < 4)
		sort_few(vars);
	else if (vars->nb_input < 50)
		sort_some(vars);
	else
		sort_many(vars);
}

void	sort_few(t_vars *vars)
{
	if (vars->nb_input == 2)
	{
		do_op(vars, &f_sa, SA);
		print_ops(vars);
	}
	sort_three(vars);
	print_ops(vars);
}

void	sort_three(t_vars *vars)
{
	find_max(vars);
	if (vars->start_a->nb == vars->max)
		do_op(vars, &f_ra, RA);
	else if (vars->start_a->next->nb == vars->max)
		do_op(vars, &f_rra, RRA);
	if (vars->start_a->nb > vars->start_a->next->nb)
		do_op(vars, &f_sa, SA);
}

void	sort_some(t_vars *vars)
{
	find_min(vars);
	while (vars->len_a > 3)
	{
		if (vars->start_a->next->nb == vars->min)
			do_op(vars, &f_sa, SA);
		else if (vars->start_a->nb == vars->min)
		{
			do_op(vars, &f_pb, PB);
			vars->len_a--;
			find_min(vars);
		}
		else if (vars->pos_min > vars->len_a / 2)
			do_op(vars, &f_ra, RA);
		else
			do_op(vars, &f_rra, RRA);
	}
	sort_three(vars);
	while (vars->start_b)
		do_op(vars, &f_pa, PA);
	print_ops(vars);
}

void	sort_many(t_vars *vars)
{
	(void)vars;

//	while (vars->start_b)
//		do_op(vars, &f_pa, PA);
	print_ops(vars);
}
