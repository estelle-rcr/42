/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 22:13:14 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/27 16:39:10 by erecuero         ###   ########.fr       */
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
/*	if (game->player.pitch > 0)
	{
		game->player.pitch = (game->player.pitch - 100 * game->ray.move_speed
					> 0)? game->player.pitch - 100 * game->ray.move_speed : 0;
	}*/
/*	if (keycode == G_KEY)
	{
		if (game->gun_choice < 4)
			game->gun_choice++;
		else
			game->gun_choice = 0;
	}*/
}

void	handle_bonus_keyrelease(int keycode, t_game *game)
{
	if (keycode == ARROW_UP)
		game->player.pitch = 0;
	if (keycode == ARROW_DOWN)
	 	game->player.pitch = 0;
}

