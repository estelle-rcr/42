/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:02:12 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/28 19:40:03 by erecuero         ###   ########.fr       */
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
	int i;

	i = 0;
	if (vars->ops)
	{
		tmp = vars->ops;
		vars->ops_list = (char *[12]){"sa", "sb", "ss", "pa", "pb", "ra", "rb",
			"rr", "rra", "rrb", "rrr", 0};
		while (tmp->next)
		{
			ft_putstr(vars->ops_list[tmp->nb]);
			ft_putstr("\n");
			i++;
			tmp = tmp->next;
		}
		ft_putstr(vars->ops_list[tmp->nb]);
		ft_putstr("\n");
	}
		ft_putstr("\n--------------------------------\n");
		ft_putstr("results:\n");
		ft_putnbr(i);
		ft_putstr(" ops\n");
		print_stacks(vars);
		ft_putstr("\n--------------------------------\n");
	exit_free(vars);
}