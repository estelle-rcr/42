/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:47:17 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/28 19:35:42 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_extended(const char *str, t_vars *vars, int *j)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while ((str[*j] >= 9 && str[*j] <= 13) || str[*j] == 32)
		(*j)++;
	if (str[*j] == '+' || str[*j] == '-')
	{
		if (str[*j] == '-')
			sign = -1;
		(*j)++;
	}
	while (str[*j] >= '0' && str[*j] <= '9')
	{
		nb = (nb * 10) + (str[*j] - '0');
		(*j)++;
	}
	if (nb * (long)sign > 2147483647 || nb * (long)sign < -2147483648)
		return (exit_free_error(vars));
	if ((str[*j] && !(str[*j] >= 9 && str[*j] <= 13) && str[*j] != 32))
									// behavior to be checked against checker on "" an " " with & without other nbs
		return (exit_free_error(vars));
	return ((int)nb * sign);
}

int	parse_args(t_vars *vars, char **av)
{
	int	nb;
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			nb = ft_atoi_extended(av[i], vars, &j);
			if (j == 1 && av[i][j - 1] == 32)
				return (exit_free(vars));
			vars->start_a = add_new_item(vars->start_a, nb);
			if (!vars->start_a)
				return (exit_free_error(vars));
		}
	}
	vars->nb_input = count_stack_nb(vars->start_a);
	return (1);
}

// function check_input checks for number list with 1 arg (exit normal)
// and for duplicates (exit error)

int	check_input(t_vars *vars)
{
	t_stack	*tmp;
	t_stack	*cmp;

	if (vars->nb_input <= 1)
		return (exit_free(vars));
	if (is_sorted(vars->start_a))
		return (exit_free(vars));
	if (vars->start_a)
	{
		tmp = vars->start_a;
		while (tmp->next)
		{
			cmp = tmp->next;
			while (cmp)
			{
				if (tmp->nb == cmp->nb)
					return (exit_free_error(vars));
				cmp = cmp->next;
			}
			tmp = tmp->next;
		}
		return (1);
	}
	return (exit_free_error(vars));
}
