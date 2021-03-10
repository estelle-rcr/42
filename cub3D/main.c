/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:27:24 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/09 22:45:02 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Do the "--save" and the floodfill algo
*/

int	main(int ac, char **av)
{
    t_game	game;
	int		save;

	save = 0;
	if (ac == 3 && ft_strlen(av[2]) == 6 && ft_strnstr(av[2], "--save", 6))
	{
		save = 1;
	}
	if (ac == 2 || (ac == 3 && save == 1))
	{
		if (!read_file(av[1], game.set))
			return (1);
		//if (!run_mlx(&game, save))
		//	return (1);
			// exit_game(&game);
			// return (1);
		// event_management(&game);
		// exit_game(&game);
		return (0);
	}
	else
	{
		print_err_msg(ERR_ARGS);
		return (1);
	}
}
