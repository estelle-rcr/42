/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:15:20 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/25 01:10:44 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int raycasting(t_game *game)
{
    double column_id;
    double ray_angle;
    float num_rays;
    int i;
    
    i = 0;
    column_id = 0.0;
    num_rays = 10; //game->set.res.x / 2;
    //num_rays = M_PI / 2;
    ray_angle = game->player.rotation_angle - (FOV / 2);
    draw_ray(game, ray_angle);
    /*
    while (i < num_rays)
    {
        draw_ray(game, ray_angle);
        ray_angle += (FOV / 2) / num_rays;
        column_id++;
        i++;
    }
    */
    return (1);
}

void	cast_all_rays(t_game *game)
{
	float	ray_angle;
	int		i;
	int		num_rays;

	i = 0;
	num_rays = game->set.res.x;
	while(i < num_rays)
	{
		ray_angle = game->player.rotation_angle + atan((i - (num_rays / 2)) / game->dst_projection_plane);
		init_ray(&game->rays[i], normalize_angle(ray_angle));
		//find_horizontal_intercept(game, &game->rays[i]);
		//find_vertical_intercept(game, &game->rays[i]);
	}
}

// is_wall_raycasting return (map[next_y][next_x])

/*
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
*/