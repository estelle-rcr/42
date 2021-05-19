/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_interaction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 00:16:23 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/30 17:27:27 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	handle_interaction(t_game *game)
{
	int	found;

	found = game->set.map[(int)(game->ray.pos.x)][(int)(game->ray.pos.y)];
	if (found == FOOD - 2 + '0' && game->player.life < 100)
	{
		game->player.life += 50;
		game->set.map[(int)(game->ray.pos.x)][(int)(game->ray.pos.y)] = '7';
	}
	if (found == IVY - 2 + '0' && game->player.life > 0)
	{
		game->player.life -= 50;
		game->set.map[(int)(game->ray.pos.x)][(int)(game->ray.pos.y)] = '7';
	}
	if (found == KEY_PU - 2 + '0')
	{
		game->player.key_found += 1;
		game->player.points += 50;
		game->set.map[(int)(game->ray.pos.x)][(int)(game->ray.pos.y)] = '7';
	}
}

void	handle_score(t_game *game, int width, int hud_h)
{
	if (game->player.points == 100)
	{
		update_hud(game, 13, (int)width / 6, hud_h / 2.4);
		update_hud(game, 15, (int)width / 5, hud_h / 2.4);
		update_hud(game, 15, (int)width / 4.3, hud_h / 2.4);
	}
	else if (game->player.points == 50)
	{
		update_hud(game, 14, (int)width / 5, hud_h / 2.4);
		update_hud(game, 15, (int)width / 4.3, hud_h / 2.4);
	}
	else
		update_hud(game, 15, (int)width / 4.3, hud_h / 2.4);
}

void	handle_life(t_game *game, int width, int hud_h)
{
	if (game->player.life == 100)
	{
		update_hud(game, 13, (int)width / 1.90, hud_h / 2.4);
		update_hud(game, 15, (int)width / 1.83, hud_h / 2.4);
		update_hud(game, 15, (int)width / 1.75, hud_h / 2.4);
	}
	else if (game->player.life == 50)
	{
		update_hud(game, 14, (int)width / 1.85, hud_h / 2.4);
		update_hud(game, 15, (int)width / 1.75, hud_h / 2.4);
	}
	else
	{
		update_hud(game, 15, (int)width / 1.85, hud_h / 2.4);
		update_hud(game, 15, (int)width / 1.75, hud_h / 2.4);
	}
}

void	handle_keys(t_game *game, int width, int hud_h)
{
	if (game->player.key_found >= 1)
		update_hud(game, 12, (int)width / 1.305, hud_h / 19);
	if (game->player.key_found >= 2)
		update_hud(game, 12, (int)width / 1.305, hud_h / 2);
}

void	end_of_game(t_game *game)
{
	if (game->player.key_found == KEYS_TO_FIND)
	{
		update_hud(game, 18, (int)game->set.res.x / 2 -
		(game->textures[WIN].width / 2), (int)game->set.res.y / 2
		- (game->textures[WIN].height / 2));
	}
	if (game->player.life == 0)
	{
		update_hud(game, 19, (int)game->set.res.x / 2 -
		(game->textures[LOSE].width / 2), (int)game->set.res.y / 2
		- (game->textures[LOSE].height / 2));
	}
}
