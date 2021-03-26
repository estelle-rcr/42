/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:15:20 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/26 15:59:20 by erecuero         ###   ########.fr       */
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
		draw_ray(game, ray_angle);
		init_ray(&game->rays[i], ray_angle);
		find_horizontal_intersept(game, &game->rays[i]);
		//find_vertical_intersept(game, &game->rays[i]);
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

void	find_horizontal_intersept(t_game *game, t_ray *ray)
{
	double	xstep;
	double	ystep;
	double	xintercept;
	double	yintercept;
	
	(void)xstep;
	(void)ystep;
	yintercept = (int)(game->player.pos.y / MAP_SIZE) * MAP_SIZE;
	xintercept = game->player.pos.x + (yintercept - game->player.pos.y) / tan(ray->angle);
}

void	find_vertical_intersept(t_game *game, t_ray *ray)
{
	(void)game;
	(void)ray;
}

void	draw_ray(t_game *game, double ray_angle)
{
    float	i;
	float	x;
	float	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 30)
	{
		x = game->player.pos.x + cos(ray_angle) * i + (PLAYER_SIZE / 2);
		y = game->player.pos.y + sin(ray_angle) * i + (PLAYER_SIZE / 2);
		if (!hit_screen(game, x, y) && printable_map(game, x, y))
			my_mlx_pixel_put(&game->img, x, y, MAP_PLAYER);	
		i++;
	}	
}

// is_wall_raycasting return (map[next_y][next_x])

