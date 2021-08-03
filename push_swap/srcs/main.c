/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:28:09 by erecuero          #+#    #+#             */
/*   Updated: 2021/07/12 16:46:20 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac < 2)
		return (0);
	else
	{
		vars = init_vars();
		if (vars == NULL)
			exit_free_error(vars);
		else if (ft_strlen(av[1]) == 1 && av[1][0] == ' ')
			exit_free_error(vars);
		else
			parse_args(vars, av);
		check_input(vars);
		sort_input(vars);
		exit_free(vars);
	}
}
