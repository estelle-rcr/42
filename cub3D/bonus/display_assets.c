/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 23:16:16 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/29 18:11:20 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_assets(t_game *game, int width, int height)
{
	draw_hud(game, width, height);
	draw_gun(game, width, height, 0);
	draw_map(game, &game->set);
	update_hud(game, 13, (int)width / 20, game->hud_size / 2.4);
	handle_score(game, width, game->hud_size);
	handle_life(game, width, game->hud_size);
	handle_keys(game, width, game->hud_size);
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

void	update_hud(t_game *game, int text, int offset_x, int offset_y)
{
	int color;
	int width;
	int y;
	int x;

	width = (int)(game->hud_size * 1 / 2.5 * game->textures[text].width
			/ game->textures[text].height);
	y = 0;
	while (y < game->hud_size * 1 / 2.5)
	{
		x = 0;
		while (x < width)
		{
			color = game->textures[text].addr[(int)(y *
					game->textures[text].height / (game->hud_size * 1 / 2.5))
					* game->textures[text].line_length / 4 +
					(int)(x * game->textures[text].width / width)];
			if (!filter_number(color))
				game->img.addr[(offset_y + y) *
					game->img.line_length / 4 + (offset_x + x)] =
					color;
			x++;
		}
		y++;
	}
}

void	draw_gun(t_game *game, int width, int height, int y)
{
	int	size;
	int	x;
	int color;
	int offset_x;

	width = width * 1 / 3;
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
			if (!filter_assets(color))
				game->img.addr[(height - size + y) *
					game->img.line_length / 4 + (offset_x + x)] = color;
			x++;
		}
		y++;
	}
}

int		filter_assets(int color)
{
	if (color == 10821783 || color == 9961608 || color == 65361 ||
		color == 65363 || color == 10229654 || color == 1285807)
		return (1);
	return (0);
}
