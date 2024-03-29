/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:13:53 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/28 19:37:09 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = NULL;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	if (stack)
		free(stack);
}

static void	free_ops(t_ops *ops)
{
	t_ops	*tmp;

	tmp = NULL;
	while (ops)
	{
		tmp = ops;
		ops = ops->next;
		free(tmp);
	}
	if (ops)
		free(ops);
}

int	exit_free_error(t_vars *vars)
{
	if (vars)
	{
		if (vars->start_a)
			free_stack(vars->start_a);
		if (vars->start_b)
			free_stack(vars->start_b);
		if (vars->ops)
			free_ops(vars->ops);
		free(vars);
		ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
	exit(1);
}

int	exit_free(t_vars *vars)
{
	if (vars)
	{
		if (vars->start_a)
			free_stack(vars->start_a);
		if (vars->start_b)
			free_stack(vars->start_b);
		if (vars->ops)
			free_ops(vars->ops);
		free(vars);
	}
	exit(0);
}
