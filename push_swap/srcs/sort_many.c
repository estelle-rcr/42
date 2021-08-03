/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:19:27 by erecuero          #+#    #+#             */
/*   Updated: 2021/07/08 20:19:09 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_block(t_vars *vars, int end)
{
	int	i;

	if (end <= 1)
		return ;
	i = -1;
	while (++i < end)
		do_op(vars, &f_pb, PB);
	find_max(vars, vars->start_b);
	vars->len_b = count_stack_nb(vars->start_b);
	while (vars->len_b > 3 && !is_rev_sorted(vars->start_b))
	{
		if (vars->start_b->next->nb == vars->max)
			do_op(vars, &f_sb, SB);
		else if (vars->start_b->nb == vars->max)
		{
			do_op(vars, &f_pa, PA);
			vars->len_b--;
			find_max(vars, vars->start_b);
		}
		else if (vars->pos_max < count_stack_nb(vars->start_b) / 2)
			do_op(vars, &f_rb, RB);
		else
			do_op(vars, &f_rrb, RRB);
	}
	sort_last_three(vars, end);
}

void	sort_last_three(t_vars *vars, int end)
{
	int	i;

	if (vars->len_b == 3)
	{
		find_min(vars, vars->start_b);
		if (vars->start_b->nb == vars->min)
			do_op(vars, &f_rb, RB);
		else if (vars->start_b->next->nb == vars->min)
			do_op(vars, &f_rrb, RRB);
	}
	if (vars->start_b->next && vars->start_b->nb < vars->start_b->next->nb)
		do_op(vars, &f_sb, SB);
	while (vars->start_b)
		do_op(vars, &f_pa, PA);
	i = 0;
	while (i < end)
	{
		do_op(vars, &f_ra, RA);
		i++;
	}
}

void	merge_blocks(t_vars *vars, int i)
{
	int	j;

	j = vars->nb_input + 1;
	i = vars->block_size + i;
	while (--i)
		do_op(vars, &f_ra, RA);
	while (--j > vars->block_size)
		do_op(vars, &f_pb, PB);
	while (vars->start_b)
	{
		find_max(vars, vars->start_a);
		find_min(vars, vars->start_a);
		if (vars->start_b->nb > vars->max && get_last_nb(vars->start_a)
			== vars->max)
			do_op(vars, &f_pa, PA);
		else if (vars->start_b->nb < vars->min && vars->start_a->nb
			== vars->min)
			do_op(vars, &f_pa, PA);
		else if (vars->start_b->nb > get_last_nb(vars->start_a)
			&& vars->start_b->nb < vars->start_a->nb)
			do_op(vars, &f_pa, PA);
		else
			do_op(vars, &f_rra, RRA);
	}
}

void	final_rotation(t_vars *vars)
{
	find_min(vars, vars->start_b);
	while (vars->start_a->nb != vars->min)
	{
		if (vars->pos_min <= vars->nb_input / 2)
			do_op(vars, &f_ra, RA);
		else
			do_op(vars, &f_rra, RRA);
	}
}

void	correct_last_values(t_vars	*vars)
{
	while (vars->start_a->nb != vars->unsorted_value)
	{
		if (vars->unsorted_pos <= vars->nb_input / 2)
			do_op(vars, &f_ra, RA);
		else
			do_op(vars, &f_rra, RRA);
	}
	do_op(vars, &f_pb, PB);
	while (!(get_last_nb(vars->start_a) < vars->unsorted_value
			&& vars->start_a->nb > vars->unsorted_value))
	{
		if (vars->unsorted_pos <= vars->nb_input / 2)
			do_op(vars, &f_ra, RA);
		else
			do_op(vars, &f_rra, RRA);
	}
	do_op(vars, &f_pa, PA);
}
