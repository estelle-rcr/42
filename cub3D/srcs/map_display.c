/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:15:06 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/18 13:17:02 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rect(t_game *game, t_axis pos, int color, int size)
{
	float	i;
	float	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((pos.x + i < game->set.res.x) && (pos.y + j < game->set.res.y) && (pos.x + i > 0) && (pos.y + j > 0))
				my_mlx_pixel_put(&game->img, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game, t_settings *set)
{
	int	i;
	int	j;
	t_axis pos;

	i = 0;
	(void)pos;
	while (set->map[i])
	{
		j = 0;
		while (set->map[i][j])
		{
			pos.x = j * MAP_SIZE;
			pos.y = i * MAP_SIZE;
			if (set->map[i][j] == '0')
				draw_rect(game, pos, MAP_GROUND, MAP_SIZE);
			else if (set->map[i][j] == '2')
				draw_rect(game, pos, MAP_SPRITES, MAP_SIZE);				
			else if (set->map[i][j] == '1')
				draw_rect(game, pos, MAP_WALL, MAP_SIZE);		
			j++;
		}
		i++;
	}
	pos.x = game->set.start_pos.x * MAP_SIZE;
	pos.y = game->set.start_pos.y * MAP_SIZE;
	draw_rect(game, pos, MAP_PLAYER, PLAYER_SIZE);
}