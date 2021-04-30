/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:15:20 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/02 11:22:35 by erecuero         ###   ########.fr       */
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

void	find_horizontal_intercept(t_game *game, t_ray *ray)
{
	t_axis	step;
	t_axis	intercept;

	intercept.y = (int)(game->player.pos.y);
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
		wall_content = is_wall(game, next_step.x, next_step.y);
		if (wall_content == '1' || wall_content == ' ')
		{
			set_axis(&ray->wall_hit, next.x, next.y);
			ray->wall_content = wall_content;
			ray->north_wall = !offset;
			ray->south_wall = !ray->north_wall;
			ray->hit_horizontal = 1;
			ray->distance = distance_btw_points(game->player.pos.x, game->player.pos.y, ray->wall_hit.x, ray->wall_hit.y);
			break ;
		}
		set_axis(&next, next.x + step.x, next.y + step.y);
	}
}

void	vertical_loop(t_game *game, t_ray *ray,
	t_axis next, t_axis step)
{
	t_axis	next_touch;
	float	offset_facing_left;
	char	wall_content;
	float	vertical_len;

	offset_facing_left = 0.0;
	if (ray->facing_left)
		offset_facing_left = 1.0;
	while (next.x >= 0 && next.x < game->set.res.x
		&& next.y >= 0 && next.y < game->set.res.y)
	{
		set_axis(&next_touch, next.x - offset_facing_left, next.y);
		wall_content = is_wall(game, next_step.x, next_step.y);
		if (wall_content == '1' || wall_content == ' ')
		{
			vertical_len = distance_btw_points(game->player.pos.x, game->player.pos.y, next.x, next.y;
			if (vertical_len < ray->distance || ray->distance == 0)
				ray->distance = vertical_len;
				set_axis(&ray->wall_hit, wall_found.x, wall_found.y);
				ray->wall_content = hit_content;
				ray->north_wall = 0;
				ray->south_wall = 0;
				ray->west_wall = !ray->facing_left;
				ray->east_wall = !ray->west_wall;
				ray->hit_vertical = 1;
			break ;
		}
		set_axis(&next, next.x + step.x, next.y + step.y);
	}
}

void	find_vertical_intercept(t_game *game, t_ray *ray)
{
	t_axis	step;
	t_axis	intercept;

	intercept.x = (int)(game->player.pos.x);
	if (ray->facing_left)
		intercept.x += 1;
	intercept.y = game->player.pos.y + ((intercept.x - game->player.pos.x) * tan(ray->angle));
	step.x = 1;
	if (!ray->facing_left)
		step.x *= -1;
	step.y = tan(ray->angle);
	if ((!ray->facing_down && step.y > 0) || (ray->facing_down && step.y < 0))
		step.y *= -1;
	vertical_loop(game, ray, intercept, step);
}

void   draw_ray(t_game *game, t_axis start, t_axis end)                          estellerecuero@MacBook-Pro
{
        t_axis  delta;
        t_axis  step;
        t_axis  pos;
        int             limit;
        int     i;

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
}
