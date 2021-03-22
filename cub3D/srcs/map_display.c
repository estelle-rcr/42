/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:15:06 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/22 15:50:49 by erecuero         ###   ########.fr       */
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
}

void draw_player(t_game *game, t_axis player_pos)
{
    float	i;
	float	j;
    t_axis pos;

	i = 0;
    pos.x = player_pos.x * PACE;
	pos.y = player_pos.y * PACE;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			if ((pos.x + i < game->set.res.x) && (pos.y + j < game->set.res.y) && (pos.x + i > 0) && (pos.y + j > 0))
				my_mlx_pixel_put(&game->img, pos.x + i, pos.y + j, MAP_PLAYER);
			j++;
		}
		i++;
	}
}

void draw_line(t_game *game, t_axis player_pos)
{
    float	i;
	float	j;
    t_axis pos;

	i = 0;
    pos.x = player_pos.x * PACE;
	pos.y = player_pos.y * PACE;
	while (i < sin(game->player.rotation_angle) * 30)
	{
		j = 0;
		while (j < cos(game->player.rotation_angle) * 30)
		{
			if ((pos.x + i < game->set.res.x) && (pos.y + j < game->set.res.y) && (pos.x + i > 0) && (pos.y + j > 0))
				my_mlx_pixel_put(&game->img, pos.x + i, pos.y + j, MAP_PLAYER);
			j++;
		}
		i++;
	}
}
/*
int hit_wall(char **map, t_axis pos)
{
    if (map[pos.y][pos.x] == )
}*/

void	init_player(t_game *game)
{
	game->player.pos.x = game->set.start_pos.x;
	game->player.pos.y = game->set.start_pos.y;
	game->player.turn_dir = 0;
	game->player.walk_dir = 0;
	game->player.rotation_angle = M_PI / 2;
	game->player.move_speed = 3.0;
	game->player.rotation_speed = 3 * (M_PI / 180);
//	game->player.radius = 3;
}



void    raycaster(t_game game, char **map)
{
    double dirX = -1;
    double dirY = 0;
    double planeX = 0;
    double planeY = 0.66;

	double time = 0;
	double oldTime = 0;


}
