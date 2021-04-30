/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 22:13:14 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/30 16:38:15 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	handle_bonus_keypress(int keycode, t_game *game)
{
	if (keycode == M_KEY)
		game->map.is_on = !game->map.is_on;
	if (keycode == ARROW_UP)
	{
		game->player.pitch += 400 * game->ray.move_speed;
		if (game->player.pitch > 200)
			game->player.pitch = 200;
	}
	if (keycode == ARROW_DOWN)
	{
		game->player.pitch -= 400 * game->ray.move_speed;
		if (game->player.pitch < -200)
			game->player.pitch = -200;
	}
}

void	handle_bonus_keyrelease(int keycode, t_game *game)
{
	if (keycode == ARROW_UP)
		game->player.pitch = 0;
	if (keycode == ARROW_DOWN)
		game->player.pitch = 0;
}
