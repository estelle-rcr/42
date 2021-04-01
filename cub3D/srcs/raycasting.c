/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:15:20 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/01 22:42:02 by erecuero         ###   ########.fr       */
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


/*
void	find_horizontal_intercept(t_game *game, t_ray *ray)
{
	t_axis	first;
	t_axis	step;

	first.y = floor(game->player.pos.y);
	if (ray->facing_down)
		first.y += 1;
	first.x = game->player.pos.x + ((first.y - game->player.pos.y) / tan(ray->angle));
	step.y = 1;
	if (!ray->facing_down)
		step.y *= -1;
	step.x = 1 / tan(ray->angle);
	if ((ray->facing_left && step.x > 0) || (!ray->facing_left && step.x < 0))
		step.x *= -1;
	find_horizontal_intercept_loop(game, ray, first, step);
}*/

void	find_horizontal_intercept(t_game *game, t_ray *ray)
{
	t_axis	step;
	t_axis	intercept;

	intercept.y = floor(game->player.pos.y);
	if (ray->facing_down)
		intercept.y += 1;
	intercept.x = game->player.pos.x + ((intercept.y - game->player.pos.y) / tan(ray->angle));
	step.y = 1;
	if (!ray->facing_down)
		step.y *= -1;
	step.x = 1 / tan(ray->angle);
	if ((ray->facing_left && step.x > 0) || (!ray->facing_left && step.x < 0))
		step.x *= -1;
	horizontal_loop(game, ray, intercept, step);
}

void	horizontal_loop(t_game *game, t_ray *ray, t_axis intercept, t_axis step)
{
	t_axis	next;
	t_axis	next_step;
	double	offset;
	char	wall_content;

	set_axis(&next, intercept.x, intercept.y);
	offset = 0.0;
	if (!ray->facing_down)
		offset = 1.0;
	while (next.x >= 0 && next.x < game->set.res.x && next.y >= 0 && next.y < game->set.res.y) //(!hit_screen(game, next.x, next.y))
	{
		set_axis(&next_step, next.x, next.y - offset);
		wall_content = is_wall(game, next_step.x, next_step.y); // is_wall_raycasting(game, next_step);
		if (wall_content == '1' || wall_content == ' ')
		{
			set_axis(&ray->wall_hit, next.x, next.y);
			//ray->distance = distance_points(game->player.pos, ray->wall_hit);
			ray->wall_content = wall_content;
			ray->north_wall = !offset;
			ray->south_wall = !ray->north_wall;
			ray->hit_horizontal = 1;
			ray->distance = distance_btw_points(game->player.pos.x, game->player.pos.y, ray->wall_hit.x, ray->wall_hit.y);
			//ray->wall_content =
			break ;
		}
		set_axis(&next, next.x + step.x, next.y + step.y);
	}
}


/*
void	horizontal_loop(t_game *game, t_ray *ray, t_axis next, t_axis step)
{
	t_axis	next_touch;
	float	offset_facing_up;
	char	wall_content;

	offset_facing_up = 0.0;
	if (!ray->facing_down)
		offset_facing_up = 1.0;
	while (next.x >= 0 && next.x < game->set.res.x
		&& next.y >= 0 && next.y < game->set.res.y)
	{
		set_axis(&next_touch, next.x, next.y - offset_facing_up);
		wall_content = is_wall_raycasting(game, next_touch);
		if (wall_content == '1' || wall_content == ' ')
		{
			set_axis(&ray->wall_hit, next.x, next.y);
			ray->distance = distance_points(game->player.pos,
				ray->wall_hit);
			ray->wall_content = wall_content;
			ray->north_wall = !offset_facing_up;
			ray->south_wall = !ray->north_wall;
			break ;
		}
		set_axis(&next, next.x + step.x, next.y + step.y);
	}
}*/

/*
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
*/
