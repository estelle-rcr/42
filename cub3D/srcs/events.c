/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:03:29 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/19 13:53:35 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == W_KEY)
		game->player.forward = 1;
	if (keycode == S_KEY)
		game->player.back = 1;
	if (keycode == D_KEY)
		game->player.right= 1;
	if (keycode == A_KEY)
		game->player.left = 1;
	if (keycode == ARROW_RIGHT)
		game->player.rotation_right = 1;
	if (keycode == ARROW_LEFT)
		game->player.rotation_left = 1;
	// BONUS_FEATURES TO ADD
	if (keycode == ESCAPE)
	{
		exit_game(game);
		mlx_loop_end(game->mlx);
		exit(0);
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
		game->player.right= 0;
	if (keycode == A_KEY)
		game->player.left = 0;
	if (keycode == ARROW_RIGHT)
		game->player.rotation_right = 0;
	if (keycode == ARROW_LEFT)
		game->player.rotation_left = 0;
	// BONUS_FEATURES TO ADD
	printf("keyrelease: %d\n", keycode); // a supprimer
	return (1);
}

/*
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
	if (keycode == G_KEY)
	{
		if (game->gun_choice < 4)
			game->gun_choice++;
		else
			game->gun_choice = 0;
	}
	if (keycode == M_KEY)
	{
		game->map.is_on = !game->map.is_on;
	}
}

void	handle_bonus_keyrelease(int keycode, t_game *game)
{
	if (keycode == ARROW_UP)
	{
		game->cf.pitch = 0;
	}
	if (keycode == ARROW_DOWN)
	{
	 	game->cf.pitch = 0;
	}
	if (keycode == E_KEY)
		game->cf.pos_z = 0;
	if (keycode == Q_KEY)
		game->cf.pos_z = 0;
}
*/
