/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:22:20 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/28 16:38:11 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_ra(t_vars *vars)
{
	t_stack	*tmp_a;
	t_stack *first;

	if (!vars->start_a)
		return (0);
	tmp_a = vars->start_a;
	first = vars->start_a;
	vars->start_a = tmp_a->next;
	while (tmp_a->next)
	{
		tmp_a = tmp_a->next;
	}
	tmp_a->next = first;
	first->next = 0;
	ft_putstr("ra\n");
	return (1);
}

int	f_rb(t_vars *vars)
{
	t_stack	*tmp_b;
	t_stack *first;

	if (!vars->start_b)
		return (0);
	tmp_b = vars->start_b;
	first = vars->start_b;
	vars->start_b = tmp_b->next;
	while (tmp_b->next)
	{
		tmp_b = tmp_b->next;
	}
	tmp_b->next = first;
	first->next = 0;
	ft_putstr("rb\n");
	return (1);
}

int	f_rr(t_vars *vars)
{
	int		ret;

	ret = 0;
	if (f_ra(vars))
		ret = 1;
	if (f_rb(vars))
		ret = 1;
	if (ret)
		ft_putstr("rr\n");
	return (ret);
}
