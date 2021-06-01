/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:28:09 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/01 16:47:03 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(t_vars *vars, int ac, char **av)
{
	int nb;
	int i;

	i = 0;
	while (av[++i])
	{
		nb = ft_atoi_extended(av[i], vars);
		if (!add_new_stack(vars->start_a, (int)nb))
			return (exit_free(vars));
	}
	vars->nb_input = ac - 1;
	printf("args :%i \n", vars->nb_input);
	printf("i :%i \n", i);
	return (1);
}

int	parse_list(t_vars *vars, char **av)
{
	int 	nb;
	int		i;
	char	**nb_list;

	nb_list = ft_split_whitespaces(av[1]);
	i = -1;
	while (nb_list[++i])
	{
		nb = ft_atoi_extended(nb_list[i], vars);
		if (!add_new_stack(vars->start_a, nb))
			return (exit_free(vars));
	}
	vars->nb_input = i;
	ft_free_tab(nb_list);
	printf("args :%i \n", vars->nb_input);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac < 2)
		return (0);
	else
	{
		printf("ac %i\n", ac);
		vars = init_vars();
		if (vars == NULL)
			exit_free(vars);
		if (ac == 2)
			parse_list(vars, av);
		else
			parse_args(vars, ac, av);
		printf("ok\n");
	}
}
