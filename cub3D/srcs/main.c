/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:27:24 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/21 15:30:19 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	game.save = 0;
	if (ac == 3 && ft_strlen(av[2]) == 6 && ft_strnstr(av[2], "--save", 6))
	{
		game.save = 1;
	}
	if (ac == 2 || (ac == 3 && game.save == 1))
	{
		if (!read_file(av[1], &game.set))
			return (1);
		if (!run_mlx(&game))
		{
			exit_game(&game);
			return (1);
		}
		return (0);
	}
	else
	{
		print_err_msg(ERR_ARGS);
		return (1);
	}
}
