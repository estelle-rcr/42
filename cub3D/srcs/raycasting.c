/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:15:20 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/30 00:07:03 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_all_rays(t_game *game)
{
	double	ray_angle;
	int		i;
	int		num_rays;

	i = 0;
	num_rays = game->set.res.x;
	while(i < num_rays)
	{
		ray_angle = game->player.rotation_angle + atan((i - (num_rays / 2)) / game->dst_projection_plane);
	    ray_angle = normalize_angle(&ray_angle);
		init_ray(&game->rays[i], ray_angle);
		find_horizontal_intercept(game, &game->rays[i]);
		find_vertical_intercept(game, &game->rays[i]);
		//draw_ray(game, &game->rays[i]);
		draw_ray_test(game, game->player.pos, game->rays[i].wall_hit);
		i++;
	}
}

double	normalize_angle(double *ray_angle)
{
	*ray_angle =  fmod(*ray_angle, 2 * M_PI);
	if (*ray_angle < 0)
		*ray_angle = (2 * M_PI) + *ray_angle;
	return (*ray_angle);
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

void	find_horizontal_intercept(t_game *game, t_ray *ray)
{
	t_axis	step;
	t_axis	intercept;
	t_axis	next;
	
	intercept.y = floor(game->player.pos.y / MAP_SIZE) * MAP_SIZE;
	intercept.y += ray->facing_down * MAP_SIZE; 
	intercept.x = game->player.pos.x + (intercept.y - game->player.pos.y) / tan(ray->angle);
	step.y = MAP_SIZE;
	if (!ray->facing_down)
		step.y *= -1;
	step.x = MAP_SIZE / tan(ray->angle);
	if ((ray->facing_right && step.x < 0) || (!ray->facing_right && step.x > 0))
		step.x *= -1;
		
	next.x = intercept.x;
	next.y = intercept.y;
	while (!hit_screen(game, next.x, next.y) && ray->hit_horizontal == 0)
	{
		if (hit_wall(game, (int)next.x / MAP_SIZE, (int)next.y / MAP_SIZE - (!ray->facing_down)))
		{
			ray->hit_horizontal = 1;
			ray->wall_hit.x = next.x;
			ray->wall_hit.y = next.y;
			ray->distance = distance_btw_points(game->player.pos.x, game->player.pos.y, ray->wall_hit.x, ray->wall_hit.y);
			//ray->wall_content = 
		}
		else
		{
			next.x += step.x;
			next.y += step.y;
		}
	}
}

void	find_vertical_intercept(t_game *game, t_ray *ray)
{
	t_axis	step;
	t_axis	intercept;
	t_axis	next;
	double	distance;
	
	intercept.x = (int)(game->player.pos.x / MAP_SIZE) * MAP_SIZE;
	intercept.x += ray->facing_right * MAP_SIZE; 
	intercept.y = game->player.pos.y + (intercept.x - game->player.pos.x) * tan(ray->angle);
	
	step.x = MAP_SIZE;
	if (!ray->facing_right)
		step.x *= -1;
	step.y= MAP_SIZE * tan(ray->angle);
	if ((ray->facing_down && step.y < 0) || (!ray->facing_down && step.y > 0))
		step.y *= -1;

	next.x = intercept.x;
	next.y = intercept.y;
		
	while (!hit_screen(game, next.x, next.y) && ray->hit_vertical == 0)
	{
		if (hit_wall(game, (int)next.x / MAP_SIZE - (!ray->facing_right), (int)next.y / MAP_SIZE))
		{
			distance = distance_btw_points(game->player.pos.x, game->player.pos.y, next.x, next.y);
			ray->hit_vertical = 1;
			if (distance < ray->distance)
			{
				ray->hit_horizontal = 0;
				ray->wall_hit.x = next.x;
				ray->wall_hit.y = next.y;
				ray->distance = distance;				
			}
		}
		else
		{
			next.x += step.x;
			next.y += step.y;
		}
	}
}

double	distance_btw_points(double x1, double y1, double x2, double y2)
{
		return (sqrt(x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void	draw_ray(t_game *game, t_ray *ray)
{
    float	i;
	float	j;
	float	x;
	float	y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i < 30 && j < 30)
	{
		x = game->player.pos.x + cos(ray->angle) * i + (PLAYER_SIZE / 2);
		y = game->player.pos.y + sin(ray->angle) * j + (PLAYER_SIZE / 2);
		if (!hit_screen(game, x, y) && printable_map(game, x, y))
			my_mlx_pixel_put(&game->img, x, y, MAP_PLAYER);	
		i++;
		j++;
	}	
}

void	draw_ray_test(t_game *game, t_axis start, t_axis end)
{
	t_axis	delta;
	t_axis	step;
	t_axis	pos;
	int		limit;
	int 	i;
	
	delta.x = end.x - start.x;
	delta.y = end.y - start.y;
	if (fabs(delta.x) > fabs(delta.y))
		limit = fabs(delta.x);
	else
		limit = fabs(delta.y);
	step.x = delta.x / (double)limit;
	step.y = delta.y / (double)limit;
	pos.x = start.x;
	pos.y = start.y;
	i = 0;
	while (i <= limit && !hit_screen(game, pos.x, pos.y) && printable_map(game, pos.x, pos.y))
	{
		my_mlx_pixel_put(&game->img, pos.x, pos.y, MAP_PLAYER);	
		pos.x += step.x;
		pos.y += step.y;
		i++;
	}
}