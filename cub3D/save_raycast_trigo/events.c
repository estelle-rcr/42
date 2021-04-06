/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:03:29 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/02 11:23:15 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == D_KEY)
	{
		game->player.walk_dir = 1;
		game->player.right = 1;
	}
	if (keycode == A_KEY)
	{
		game->player.walk_dir = 1;
		game->player.left = 1;
	}
	if (keycode == ARROW_UP || keycode == W_KEY)
		game->player.walk_dir = 1;
	if (keycode == ARROW_DOWN || keycode == S_KEY)
		game->player.walk_dir = -1;
	if (keycode == ARROW_RIGHT)
		game->player.turn_dir = 1;
	if (keycode == ARROW_LEFT)
		game->player.turn_dir = -1;
	if (keycode == ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	return (1);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == D_KEY)
	{
		game->player.walk_dir = 0;
		game->player.right = 0;
	}
	if (keycode == A_KEY)
	{
		game->player.walk_dir = 0;
		game->player.left = 0;
	}
	if (keycode == ARROW_UP || keycode == W_KEY)
		game->player.walk_dir = 0;
	if (keycode == ARROW_DOWN || keycode == S_KEY)
		game->player.walk_dir = 0;
	if (keycode == ARROW_RIGHT)
		game->player.turn_dir = 0;
	if (keycode == ARROW_LEFT)
		game->player.turn_dir = 0;
	printf("keyrelease: %d\n", keycode); // a supprimer
	return (1);
}
