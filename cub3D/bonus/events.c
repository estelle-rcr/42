/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:03:29 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/18 22:12:43 by erecuero         ###   ########.fr       */
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
		mlx_loop_end(game->mlx);
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