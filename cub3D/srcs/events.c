/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:03:29 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/18 15:29:32 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ARROW_UP || keycode == W_KEY)
		game->set.player_pos.y -= 1;
	else if (keycode == ARROW_DOWN || keycode == S_KEY)
		game->set.player_pos.y += 1;
	else if (keycode == ARROW_LEFT || keycode == A_KEY)
		game->set.player_pos.x -= 1;
	else if (keycode == ARROW_RIGHT || keycode == D_KEY)
		game->set.player_pos.x += 1;
	else if (keycode == ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	return (1);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	(void)game;
	printf("keyrelease: %d\n", keycode);
	return (1);
}