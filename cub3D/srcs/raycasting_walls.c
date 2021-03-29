/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_walls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 23:08:35 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/29 23:09:27 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	fishbowl(t_game *game, t_ray *ray)
{
	double	distance;
	double	angle;
	double	wall_height;
	
	angle = ray->angle - normalize_angle(&game->player.rotation_angle);
	distance = ray->distance * cos(angle);
	wall_height = game->dst_projection_plane / distance;
	return (wall_height);
}

void	render_wall(t_game *game)
{
	double	wall_height;
	int		i;
	
	i = 0;
	while (i < game->set.res.x)
	{
		wall_height = game->dst_projection_plane / game->rays[i].distance;
		//fishbowl
		draw_wall(game, &game->rays[i], wall_height, i);
		//map_texture;
		i++;
	}
}

void	draw_wall(t_game *game, t_ray *ray, double wall_height, int ray_index)
{
	//t_axis text_offset;
	int y;
	int color;
	int top_pixel;
	int	bottom_pixel;
	
	wall_setup(game->set.res, wall_height, &top_pixel, &bottom_pixel);
	y = top_pixel;
	//text_offset
	while(y < bottom_pixel)
	{
		color = WALL_COLOR;
		my_mlx_pixel_put(&game->img, ray_index, y, color);
		y++;
	}
}

void	wall_setup(t_axis res, double wall_height, int *top_pixel, int *bottom_pixel)
{
	*top_pixel = (res.y / 2) - (wall_height / 2);
	if (*top_pixel < 0)
		*top_pixel = 0;
	*bottom_pixel = (res.y / 2) + (wall_height / 2);
	if (*bottom_pixel > res.y)
		*bottom_pixel = 0;
}