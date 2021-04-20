/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:15:06 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/18 22:07:59 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	hit_screen(t_game *game, float x, float y)
{
	if (x >= 0 && y >= 0 && x <= (float)game->set.res.x &&  y <= (float)game->set.res.y)
		return (0);
	return (1);
}

int printable_map(t_game *game, float x, float y)
{
	if (!game->set.map[(int)y / game->map.size] || (int)y / game->map.size >
			game->set.map_height)
		return (0);
	else if (!game->set.map[(int)y / game->map.size][(int)x / game->map.size])
		return (0);
	else if ((int)x / game->map.size > (int)ft_strlen(game->set.map[(int)y /
				game->map.size]))
		return (0);
	else if (strchr(MAP_CHARSET,
				(int)game->set.map[(int)y / game->map.size][(int)x /
						game->map.size]))
		return(1);
	return (0);
}

void	draw_player(t_game *game)
{
    float	i;
	float	j;
	float x;
	float y;

	i = 0;
	while (i < PLAYER_SIZE && game->map.is_on == 1)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			x = game->ray.pos.x * game->set.res.x * 1 / 8 + j;
			y = game->ray.pos.x  * game->set.res.y * 1 / 8 + i;
			if (!hit_screen(game, x, y) && !printable_map(game, x, y))
				my_mlx_pixel_put(&game->img, x, y, MAP_PLAYER);
			j++;
		}
		i++;
	}
}

void	draw_rect(t_game *game, t_axis pos, t_axis end, int color)
{
	float	i;
	float	j;

	i = 0;
	while (pos.x + i < end.x && game->map.is_on == 1)
	{
		j = 0;
		while (pos.y + j < end.y)
		{
			if (!hit_screen(game, pos.x + i, pos.y + j))
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

	i = 0;
	ft_bzero(&game->map, sizeof(t_map));
	game->map.size = game->set.res.x * 1 / 8;
	while (set->map[i] && game->map.is_on == 1)
	{
		j = 0;
		while (set->map[i][j])
		{
			game->map.start.x = j * game->map.size;
			game->map.start.y = i * game->map.size;
			game->map.end.x = game->map.start.x + game->map.size;
			game->map.end.y = game->map.start.y + game->map.size;
			if (set->map[i][j] == '0')
				draw_rect(game, game->map.start, game->map.end, MAP_GROUND);
			else if (set->map[i][j] == '2')
				draw_rect(game, game->map.start, game->map.end, MAP_SPRITES);
			else if (set->map[i][j] == '1')
				draw_rect(game, game->map.start, game->map.end, MAP_WALL);
			j++;
		}
		i++;
	}
	draw_player(game);
}

/*
void	draw_ray(t_game *game, t_axis start, t_axis end)
{
	t_axis	delta;
	t_axis	step;
	t_axis	pos;
	int		limit;
	int 	i;

	delta.x = (end.x * MAP_SIZE) - (start.x * MAP_SIZE);
	delta.y = (end.y * MAP_SIZE) - (start.y * MAP_SIZE);
	if (fabs(delta.x) > fabs(delta.y))
		limit = fabs(delta.x);
	else
		limit = fabs(delta.y);
	step.x = (delta.x / (double)limit);
	step.y = (delta.y / (double)limit);
	pos.x = start.x * MAP_SIZE; //+ (PLAYER_SIZE / 2)
	pos.y = start.y * MAP_SIZE; //+ (PLAYER_SIZE / 2)
	i = 0;
	while (i < limit && !hit_screen(game, pos.x, pos.y) && printable_map(game, pos.x, pos.y))
	{
		my_mlx_pixel_put(&game->img, pos.x, pos.y, MAP_PLAYER);
		pos.x += step.x;
		pos.y += step.y;
		i++;
	}
}*/
