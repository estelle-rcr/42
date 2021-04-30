/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:15:06 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/29 00:10:10 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_map(t_game *game)
{
	game->map.start.x = 0;
	game->map.start.y = 0;
	game->map.end.x = 0;
	game->map.end.y = 0;
	game->map.is_on = 0;
	game->map.size = 0;
}

void	draw_player(t_game *game)
{
	float	i;
	float	j;
	float	x;
	float	y;

	i = 0;
	x = (int)game->ray.pos.x * game->map.size + (int)(game->hud_size + 20);
	y = (int)game->ray.pos.y * game->map.size + (int)(game->map.size / 2);
	while (i < game->map.size && game->map.is_on == 1)
	{
		j = 0;
		while (j < game->map.size)
		{
			if (!hit_screen(game, x, y))
				game->img.addr[(int)(x + j) * game->img.line_length / 4 +
					(int)(y + i)] = MAP_PLAYER;
			j++;
		}
		i++;
	}
}

void	draw_rect(t_game *game, t_axis pos, t_axis end, int color)
{
	int	i;
	int	j;

	i = 0;
	while (pos.x + i < end.x)
	{
		j = 0;
		while (pos.y + j < end.y)
		{
			if (!hit_screen(game, pos.x + j, pos.y + i))
				game->img.addr[(int)(pos.y + j) * game->img.line_length / 4
					+ (int)(pos.x + i)] = color;
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game, t_settings *set)
{
	int	i;
	int	j;

	i = 0;
	game->map.size = (int)(game->set.res.x * 0.008);
	while (set->map[i] && game->map.is_on == 1)
	{
		j = 0;
		while (set->map[i][j])
		{
			game->map.start.x = j * game->map.size + (int)(game->map.size / 2);
			game->map.start.y = i * game->map.size + (int)(game->hud_size + 20);
			game->map.end.x = game->map.start.x + game->map.size;
			game->map.end.y = game->map.start.y + game->map.size;
			if (set->map[i][j] == '0')
				draw_rect(game, game->map.start, game->map.end, MAP_GROUND);
			else if (ft_strchr(SPRITE_CHARSET, set->map[i][j]))
				draw_rect(game, game->map.start, game->map.end, MAP_SPRITES);
			else if (set->map[i][j] == '1')
				draw_rect(game, game->map.start, game->map.end, MAP_WALL);
			j++;
		}
		i++;
	}
	draw_player(game);
}
