/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hud.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 23:16:16 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/28 00:13:13 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_assets(t_game *game, int width, int height)
{
	draw_hud(game, width, height);
	draw_gun(game, width, height, 0);
}

void	draw_hud(t_game *game, int width, int height)
{
	int	y;
	int	x;
	int offset;

	y = 0;
	game->hud_size = (int)(game->textures[HUD_D].height * width /
			game->textures[HUD_D].width);
	offset = height - (game->hud_size + 1);
	while (y < game->hud_size)
	{
		x = 0;
		while (x < width)
		{
			if (!hit_screen(game, x, y))
				game->img.addr[(y) * game->img.line_length / 4 + x] =
					game->textures[HUD_D].addr[(int)(y *
					game->textures[HUD_D].height / game->hud_size) *
					game->textures[HUD_D].line_length / 4 +
					(int)(x * game->textures[HUD_D].width / width)];
			x++;
		}
		y++;
	}
}

/*
void	update_hud(t_game *game)
{

}
*/

void	draw_gun(t_game *game, int width, int height, int y)
{
	int	size;
	int	x;
	int color;
	int offset_x;

	width = width * 1/3;
	size = (int)(game->textures[MP_HUD].height * width /
				game->textures[MP_HUD].width);
	offset_x = (width) - ((int)(game->textures[MP_HUD].width) / 2);
	while (y < size)
	{
		x = 0;
		while (x < width)
		{
			color = game->textures[MP_HUD].addr[(int)(y * 
					game->textures[MP_HUD].height / size) *
					game->textures[MP_HUD].line_length / 4 +
					(int)(x * game->textures[MP_HUD].width / width)];
			if (!filter_sprite_bg(color))
					game->img.addr[(height - (size + 0) + y) *
					game->img.line_length / 4 + (offset_x + x)] = color;
			x++;
		}
		y++;
	}
}