/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:27:24 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/04 15:25:28 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Do the "--save" and the floodfill algo
*/

int	main(int ac, char **av)
{
    t_settings *set;

	if (ac == 3 && ft_strlen(av[2]) == 6 && ft_strnstr(av[2], "--save", 6))
	{
		(void)ac;
		(void)av;
	}
	if (ac == 2 || ac == 3)
	{
		set = read_file(av[1]);
		run_mlx(set);
		return (0);
	}
	else
	{
		print_err_msg(ERR_NUMBER_ARGS);
		return (1);
	}
}
