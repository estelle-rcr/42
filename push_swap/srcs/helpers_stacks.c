/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:06:57 by erecuero          #+#    #+#             */
/*   Updated: 2021/07/08 20:17:15 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_stack_nb(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (stack)
	{
		tmp = stack;
		while (tmp->next)
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (++i);
}

int	is_sorted(t_vars *vars, t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*cmp;
	int		i;

	find_max(vars, stack);
	i = 0;
	if (stack)
	{
		tmp = stack;
		while (tmp->next)
		{
			cmp = tmp->next;
			if (tmp->nb > cmp->nb)
			{
				attribute_pos_value(vars, i, tmp->nb, tmp->next->nb);

				return (0);
			}
			tmp = tmp->next;
			i++;
		}
	}
	return (1);
}

void	attribute_pos_value(t_vars *vars, int i, int nb, int next_nb)
{
	if (nb == vars->max)
	{
		vars->unsorted_pos = i++;
		vars->unsorted_value = next_nb;
	}
	else
	{
		vars->unsorted_pos = i;
		vars->unsorted_value = nb;
	}
}

int	is_rev_sorted(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*cmp;

	if (stack)
	{
		tmp = stack;
		while (tmp->next)
		{
			cmp = tmp->next;
			while (cmp)
			{
				if (tmp->nb < cmp->nb)
					return (0);
				cmp = cmp->next;
			}
			tmp = tmp->next;
		}
	}
	return (1);
}
