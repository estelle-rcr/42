/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:19:27 by erecuero          #+#    #+#             */
/*   Updated: 2021/07/12 16:40:54 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_input(t_vars *vars)
{
	vars->len_a = vars->nb_input;
	if (vars->nb_input < 4)
		sort_few(vars);
	else if (vars->nb_input < 55)
		sort_some(vars);
	else
		sort_many(vars);
	print_ops(vars);
}

void	sort_few(t_vars *vars)
{
	find_max(vars, vars->start_a);
	if (vars->len_a == 3)
	{
		if (vars->start_a->nb == vars->max)
			do_op(vars, &f_ra, RA);
		else if (vars->start_a->next->nb == vars->max)
			do_op(vars, &f_rra, RRA);
	}
	if (vars->start_a->nb > vars->start_a->next->nb)
		do_op(vars, &f_sa, SA);
}

void	sort_some(t_vars *vars)
{
	find_min(vars, vars->start_a);
	while (vars->len_a > 3 && !is_sorted(vars, vars->start_a))
	{
		if (vars->len_a > 2 && vars->start_a->next->nb == vars->min)
			do_op(vars, &f_sa, SA);
		if (vars->start_a->nb == vars->min)
		{
			do_op(vars, &f_pb, PB);
			vars->len_a--;
			find_min(vars, vars->start_a);
		}
		else if (vars->pos_min < vars->len_a / 2)
			do_op(vars, &f_ra, RA);
		else
			do_op(vars, &f_rra, RRA);
	}
	sort_few(vars);
	while (vars->start_b)
		do_op(vars, &f_pa, PA);
}

void	sort_many(t_vars *vars)
{
	int	i;
	int	divider;

	i = 0;
	if (vars->nb_input < 300)
		divider = 5;
	else if (vars->nb_input < 1000)
		divider = vars->nb_input / 100 * 2;
	else
		divider = 20;
	vars->block_size = vars->nb_input / divider;
	i = vars->nb_input;
	while (i > 0)
	{
		sort_by_block(vars, vars->block_size);
		i = i - vars->block_size;
	}
	merge_blocks(vars, i);
	final_rotation(vars);
	while (!is_sorted(vars, vars->start_a))
	{
		correct_last_values(vars);
		final_rotation(vars);
	}
}
