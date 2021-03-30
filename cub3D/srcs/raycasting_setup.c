/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 00:58:49 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/30 16:39:41 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	hit_screen(t_game *game, float x, float y)
{
	if (x >= 0 && y >= 0 && x <= (float)game->set.res.x &&  y <= (float)game->set.res.y)
		return (0);
	return (1);
}

void	draw_rect(t_game *game, t_axis pos, t_axis end, int color)
{
	float	i;
	float	j;

	i = 0;
	while (pos.x + i < end.x)
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

void	render_background(t_game *game)
{
	t_axis	ceil_start;
	t_axis	ceil_end;
	t_axis	floor_start;
	t_axis	floor_end;

	ceil_start.x = 0;
	ceil_start.y = 0;
	ceil_end.x = game->set.res.x;
	ceil_end.y = game->set.res.y / 2;
	floor_start.x = 1;
	floor_start.y = game->set.res.y / 2;
	floor_end.x = game->set.res.x;
	floor_end.y = game->set.res.y;
	draw_rect(game, ceil_start, ceil_end, game->set.c_color);
	draw_rect(game, floor_start, floor_end, game->set.f_color);
}

void	update_player(t_game *game, t_player *player)
{
	float move_step;
	t_axis next;
	t_axis step;
	
	player->rotation_angle += player->turn_dir * player->rotation_speed;
	move_step = player->walk_dir * player->move_speed;
	step.x = cos(player->rotation_angle) + game->player.direction_angle;
	step.y = sin(player->rotation_angle) + game->player.direction_angle;
    next.x = player->pos.x + (step.x * move_step);
	next.y = player->pos.y + (step.y * move_step);
	if (!hit_wall(game, (int)(next.x / MAP_SIZE), (int)(next.y / MAP_SIZE)))
	{
		player->pos.x = next.x;
		player->pos.y = next.y;
	
	}
	game->player.rotation_angle = normalize_angle(&game->player.rotation_angle);
	draw_player(game);
}

/*	if (!hit_wall(game, (int)(next.x / game->set.res.x), (int)(next.y/ game->set.res.y)))
	{
		player->pos.x = next.x;
		player->pos.y = next.y;
		draw_player(game);
	}	*/
//	game->player.rotation_angle = normalize_angle(&game->player.rotation_angle);

int	is_wall(t_game *game, float x, float y)
{
	int	index_x;
	int index_y;
	
	char **map;
	t_axis map_res;

	map = game->set.map;
	map_res = game->set.res;
	index_x = floor(x);
	index_y = floor(y);
	if (index_x < 0 || index_y < 0 || index_x >= map_res.x || index_y >= map_res.y)
		return(1);
	if (index_y / MAP_SIZE <= game->set.map_height && map[index_y / MAP_SIZE] && map[index_y / MAP_SIZE][index_x / MAP_SIZE])
		return (map[index_y / MAP_SIZE][index_x / MAP_SIZE]);
	return (0);
}

int hit_wall(t_game *game, int x, int y)
{
	char **map;

	map = game->set.map;
    if (y > game->set.map_height || !map[y] || !map[y][x])
		return (1);
	else if (map[y][x] == '1')
		return (1);
	else
		return (0);
}