/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:15:20 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/30 17:02:21 by erecuero         ###   ########.fr       */
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
		draw_ray(game, game->player.pos, game->rays[i].wall_hit);
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

void	find_horizontal_intercept(t_game *game, t_ray *ray)
{
	t_axis	step;
	t_axis	intercept;
	t_axis	next;
	double	offset;
	char	wall_content;
	
	intercept.y = floor(game->player.pos.y / MAP_SIZE) * MAP_SIZE;
	intercept.y += ray->facing_down * MAP_SIZE; 
	intercept.x = game->player.pos.x + (intercept.y - game->player.pos.y) / tan(ray->angle);
	step.y = MAP_SIZE;
	if (!ray->facing_down)
		step.y *= -1;
	step.x = MAP_SIZE / tan(ray->angle);
	if ((ray->facing_left && step.x > 0) || (!ray->facing_left && step.x < 0))
		step.x *= -1;
	next.x = intercept.x;
	next.y = intercept.y;
	offset = 0.0;
	if ((!ray->facing_down))
		offset = 1.0;
	while (!hit_screen(game, next.x, next.y))
	{
		wall_content = is_wall(game, next.x, next.y - offset); // 
		if (wall_content == '1') 
		{
			ray->hit_horizontal = 1;
			ray->wall_hit.x = next.x;
			ray->wall_hit.y = next.y;
			ray->north_wall = ray->facing_down;
			ray->south_wall = !ray->facing_down;
			ray->distance = distance_btw_points(game->player.pos.x, game->player.pos.y, ray->wall_hit.x, ray->wall_hit.y);
			//ray->wall_content = 
			break;
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
	char wall_content;
	
	intercept.x = (int)(game->player.pos.x / MAP_SIZE) * MAP_SIZE;
	if (!ray->facing_down)
		intercept.x += 1 * MAP_SIZE; 
	intercept.y = game->player.pos.y + (intercept.x - game->player.pos.x) * tan(ray->angle);
	
	step.x = MAP_SIZE;
	if (ray->facing_left)
		step.x *= -1;
	step.y= MAP_SIZE * tan(ray->angle);
	if ((ray->facing_down && step.y < 0) || (!ray->facing_down && step.y > 0))
	{
		step.y *= -1;
	//	printf(" step y %f \n", step.y);
	}
	next.x = intercept.x;
	next.y = intercept.y;		
	while (!hit_screen(game, next.x, next.y))
	{
		wall_content = is_wall(game, next.x- (ray->facing_left), next.y); // 
		if (wall_content == '1') 
		{
			distance = distance_btw_points(game->player.pos.x, game->player.pos.y, next.x, next.y);		
			if (distance < ray->distance)
			{	
				ray->hit_vertical = 1;
				ray->hit_horizontal = 0;
				ray->wall_hit.x = next.x;
				ray->wall_hit.y = next.y;
				ray->north_wall = 0;
				ray->south_wall = 0;
				ray->west_wall = ray->facing_left;
				ray->east_wall = !ray->facing_left;
				ray->distance = distance;			
			}
			break;	
		}
		else
		{
			next.x += step.x;
			next.y += step.y;
			ray->next_x += step.x;
			ray->next_y += step.y;
		}
	}
}

double	distance_btw_points(double x1, double y1, double x2, double y2)
{
		return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	draw_ray(t_game *game, t_axis start, t_axis end)
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
	pos.x = start.x; //+ (PLAYER_SIZE / 2)
	pos.y = start.y; //+ (PLAYER_SIZE / 2)
	i = 0;
	while (i < limit && !hit_screen(game, pos.x, pos.y) && printable_map(game, pos.x, pos.y))
	{
		my_mlx_pixel_put(&game->img, pos.x, pos.y, MAP_PLAYER);	
		pos.x += step.x;
		pos.y += step.y;
		i++;
	}
}