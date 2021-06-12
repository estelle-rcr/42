/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:28:09 by erecuero          #+#    #+#             */
/*   Updated: 2021/06/03 18:59:36 by erecuero         ###   ########.fr       */
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
			exit_free(vars);
		if (ac == 2)
			parse_list(vars, av);
		else
			parse_args(vars, av);
		check_input(vars);
//		sort_input(vars);
		exit_free(vars);
	}
}
