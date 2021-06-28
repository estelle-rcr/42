/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:02:12 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/28 19:21:54 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_vars *vars)
{
	t_stack	*tmp;
	t_stack	*tmp_b;

	if (vars->start_a)
	{
		ft_putstr("\nStack A:\n");
		tmp = vars->start_a;
		while (tmp->next)
		{
			ft_putnbr(tmp->nb);
			ft_putstr(" ");
			tmp = tmp->next;
		}
		ft_putnbr(tmp->nb);
		ft_putstr(" \n");
	}
	if (vars->start_b)
	{
		ft_putstr("\nStack B:\n");
		tmp_b = vars->start_b;
		while (tmp_b->next)
		{
			ft_putnbr(tmp_b->nb);
			ft_putstr(" ");
			tmp_b = tmp_b->next;
		}
		ft_putnbr(tmp_b->nb);
		ft_putstr(" \n");
	}
	ft_putstr("\n----------------------\n");
}

void	print_ops(t_vars *vars)
{
	t_ops	*tmp;

	if (vars->ops)
	{
		tmp = vars->ops;
		vars->ops_list = (char *[12]){"sa", "sb", "ss", "pa", "pb", "ra", "rb",
			"rr", "rra", "rrb", "rrr", 0};
		while (tmp->next)
		{
			ft_putstr(vars->ops_list[tmp->nb]);
			ft_putstr("\n");
			tmp = tmp->next;
		}
		ft_putstr(vars->ops_list[tmp->nb]);
	}
}

void final_output(t_vars *vars)
{
	/*	ft_putstr("\n--------------------------------\n");
	ft_putstr("to be sorted");
	print_stacks(vars);
	ft_putstr("\n--------------------------------\n");*/
//	f_sa(vars);
//	vars->ops = add_new_op(vars->ops, SA);
//	print_stacks(vars);
	ft_putstr("\n--------------------------------\n");
	ft_putstr("results:\n");
	print_ops(vars);
	ft_putstr("\n--------------------------------\n");
/*	f_pb(vars);
		print_stacks(vars);
	f_pb(vars);
		print_stacks(vars);
	f_sa(vars);
		print_stacks(vars);
	f_pa(vars);
		print_stacks(vars);
	f_pa(vars);
		print_stacks(vars);
	f_pa(vars);
		print_stacks(vars);*/
}
