/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:15:06 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/29 14:17:06 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_game *game, t_settings *set)
{
	int	i;
	int	j;
	t_axis start;
	t_axis end;

	i = 0;
	while (set->map[i])
	{
		j = 0;
		while (set->map[i][j])
		{
			start.x = j * MAP_SIZE;
			start.y = i * MAP_SIZE;
			end.x = start.x + MAP_SIZE;
			end.y = start.y + MAP_SIZE;
			if (set->map[i][j] == '0')
				draw_rect(game, start, end, MAP_GROUND);
			else if (set->map[i][j] == '2')
				draw_rect(game, start, end, MAP_SPRITES);				
			else if (set->map[i][j] == '1')
				draw_rect(game, start, end, MAP_WALL);		
			j++;
		}
		i++;
	}
}

void draw_player(t_game *game)
{
    float	i;
	float	j;
	int x;
	int y;

	i = 0;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			x = game->player.pos.x + j;
			y = game->player.pos.y + i;
			if (!hit_screen(game, x, y))
				my_mlx_pixel_put(&game->img, x, y, MAP_PLAYER);
			j++;
		}
		i++;
	}
}
/*
void	draw_line(t_game *game)
{
    float	i;
	float	x;
	float	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 15)
	{
		x = game->player.pos.x + cos(game->player.rotation_angle) * i + (PLAYER_SIZE / 2);
		y = game->player.pos.y + sin(game->player.rotation_angle) * i + (PLAYER_SIZE / 2);
		if (!hit_screen(game, x, y) && printable_map(game, x, y))
			my_mlx_pixel_put(&game->img, x, y, MAP_PLAYER);	
		i++;
	}	
}*/

int printable_map(t_game *game, float x, float y)
{
	if (!game->set.map[(int)y / MAP_SIZE] || (int)y / MAP_SIZE > game->set.map_height)
		return (0);
	else if (!game->set.map[(int)y / MAP_SIZE][(int)x / MAP_SIZE])
		return (0);
	else if ((int)x / MAP_SIZE > (int)ft_strlen(game->set.map[(int)y / MAP_SIZE]))
		return (0);		
	else if (strchr(MAP_CHARSET,
				(int)game->set.map[(int)y / MAP_SIZE][(int)x / MAP_SIZE]))
		return(1);
	return (0);
}