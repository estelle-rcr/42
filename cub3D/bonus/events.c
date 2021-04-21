/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:28:07 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/21 21:13:54 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->player.forward = 1;
	if (keycode == S_KEY)
		game->player.back = 1;
	if (keycode == D_KEY)
		game->player.right = 1;
	if (keycode == A_KEY)
		game->player.left = 1;
	if (keycode == ARROW_RIGHT)
		game->player.rotation_right = 1;
	if (keycode == ARROW_LEFT)
		game->player.rotation_left = 1;
	if (keycode == ESCAPE)
	{
		exit_game(game);
	}
	return (1);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->player.forward = 0;
	if (keycode == S_KEY)
		game->player.back = 0;
	if (keycode == D_KEY)
		game->player.right = 0;
	if (keycode == A_KEY)
		game->player.left = 0;
	if (keycode == ARROW_RIGHT)
		game->player.rotation_right = 0;
	if (keycode == ARROW_LEFT)
		game->player.rotation_left = 0;
	return (1);
}
