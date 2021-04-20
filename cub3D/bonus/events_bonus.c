/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 22:13:14 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/18 22:20:34 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	handle_bonus_keypress(int keycode, t_game *game)
{
	if (keycode == ARROW_UP)
	{
		game->cf.pitch += 400 * game->ray.move_speed;
		if (game->cf.pitch > 200)
			game->cf.pitch = 200;
	}
	if (keycode == ARROW_DOWN)
	{
	 	game->cf.pitch -= 400 * game->ray.move_speed;
		if (game->cf.pitch < -200)
			game->cf.pitch = -200;
	}
	if (keycode == E_KEY)					//jump
		game->cf.pos_z = 200;
	if (keycode == Q_KEY)					//crouch
		game->cf.pos_z = -200;
	look_up_down(game, &game->cf);
/*	if (keycode == G_KEY)
	{
		if (game->gun_choice < 4)
			game->gun_choice++;
		else
			game->gun_choice = 0;
	}*/
	if (keycode == M_KEY)
	{
		game->map.is_on = !game->map.is_on;
	}
}

void	handle_bonus_keyrelease(int keycode, t_game *game)
{
	if (keycode == ARROW_UP)
		game->cf.pitch = 0;
	if (keycode == ARROW_DOWN)
	 	game->cf.pitch = 0;
	if (keycode == E_KEY)
		game->cf.pos_z = 0;
	if (keycode == Q_KEY)
		game->cf.pos_z = 0;
}

