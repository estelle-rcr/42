/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:47:17 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/08 15:13:08 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_extended(const char *str, t_vars *vars)
{
	int		sign;
	long	nb;

	sign = 1;
	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	if (nb * (long)sign > 2147483647 || nb * (long)sign < -2147483648)
		return (exit_free_error(vars));
	if (*str && (!(*str >= 9 && *str <= 13) || *str != 32))
		return (exit_free_error(vars));
	return ((int)nb * sign);
}

int	parse_args(t_vars *vars, char **av)
{
	int	nb;
	int	i;

	i = 0;
	while (av[++i])
	{
		nb = ft_atoi_extended(av[i], vars);
		vars->start_a = add_new_stack(vars->start_a, nb);
		if (!vars->start_a)
			return (exit_free_error(vars));
	}
	vars->nb_input = i - 1;
	return (1);
}

int	parse_list(t_vars *vars, char **av)
{
	int		nb;
	int		i;
	char	**nb_list;

	nb_list = ft_split_whitespaces(av[1]);
	i = -1;
	while (nb_list[++i])
	{
		nb = ft_atoi_extended(nb_list[i], vars);
		vars->start_a = add_new_stack(vars->start_a, nb);
		if (!vars->start_a)
			return (exit_free_error(vars));
	}
	if (nb_list)
		ft_free_tab(nb_list);
	vars->nb_input = i;
	return (1);
}

// function check_input checks for number list with 1 arg (exit normal)
// and for duplicates (exit error)

int	check_input(t_vars *vars)
{
	t_stack	*tmp;
	t_stack	*cmp;

	if (vars->nb_input == 1)
		return (exit_free(vars));
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
