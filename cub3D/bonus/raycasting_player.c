/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:31:08 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/28 18:21:23 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_forward_back(t_ray *ray, t_player *player, char **map)
{
	if (player->forward)
	{
		if (ft_strchr(WALKABLE_CHARSET, map[(int)(ray->pos.x + (ray->dir.x *
			ray->move_speed))][(int)ray->pos.y]))
			ray->pos.x += ray->dir.x * ray->move_speed;
		if (ft_strchr(WALKABLE_CHARSET, map[(int)(ray->pos.x)][(int)(ray->pos.y
			+ (ray->dir.y * ray->move_speed))]))
			ray->pos.y += ray->dir.y * ray->move_speed;
	}
	if (player->back)
	{
		if (ft_strchr(WALKABLE_CHARSET, map[(int)(ray->pos.x - ray->dir.x *
			ray->move_speed)][(int)ray->pos.y]))
			ray->pos.x -= ray->dir.x * ray->move_speed;
		if (ft_strchr(WALKABLE_CHARSET, map[(int)(ray->pos.x)][(int)(ray->pos.y
			- ray->dir.y * ray->move_speed)]))
			ray->pos.y -= ray->dir.y * ray->move_speed;
	}
}

void	move_left_right(t_ray *ray, t_player *player, char **map)
{
	if (player->right)
	{
		if (ft_strchr(WALKABLE_CHARSET, map[(int)(ray->pos.x + ray->dir.y *
			ray->move_speed)][(int)ray->pos.y]))
			ray->pos.x += ray->dir.y * ray->move_speed;
		if (ft_strchr(WALKABLE_CHARSET, map[(int)(ray->pos.x)][(int)(ray->pos.y
			- ray->dir.x * ray->move_speed)]))
			ray->pos.y -= ray->dir.x * ray->move_speed;
	}
	if (player->left)
	{
		if (ft_strchr(WALKABLE_CHARSET, map[(int)(ray->pos.x - ray->dir.y *
			ray->move_speed)][(int)ray->pos.y]))
			ray->pos.x -= ray->dir.y * ray->move_speed;
		if (ft_strchr(WALKABLE_CHARSET, map[(int)(ray->pos.x)][(int)(ray->pos.y
			+ ray->dir.x * ray->move_speed)]))
			ray->pos.y += ray->dir.x * ray->move_speed;
	}
}

void	rotation_left_right(t_ray *ray, t_player *player)
{
	double old_dir_x;
	double old_plane_x;

	if (player->rotation_right)
	{
		old_dir_x = ray->dir.x;
		ray->dir.x = ray->dir.x * cos(-ray->rotation_speed) - ray->dir.y *
			sin(-ray->rotation_speed);
		ray->dir.y = old_dir_x * sin(-ray->rotation_speed) + ray->dir.y *
			cos(-ray->rotation_speed);
		old_plane_x = ray->plane.x;
		ray->plane.x = ray->plane.x * cos(-ray->rotation_speed) - ray->plane.y *
			sin(-ray->rotation_speed);
		ray->plane.y = old_plane_x * sin(-ray->rotation_speed) + ray->plane.y *
			cos(-ray->rotation_speed);
	}
	if (player->rotation_left)
	{
		rotation_left(ray);
	}
}

void	rotation_left(t_ray *ray)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = ray->dir.x;
	ray->dir.x = ray->dir.x * cos(ray->rotation_speed) - ray->dir.y *
		sin(ray->rotation_speed);
	ray->dir.y = old_dir_x * sin(ray->rotation_speed) + ray->dir.y *
		cos(ray->rotation_speed);
	old_plane_x = ray->plane.x;
	ray->plane.x = ray->plane.x * cos(ray->rotation_speed) - ray->plane.y *
		sin(ray->rotation_speed);
	ray->plane.y = old_plane_x * sin(ray->rotation_speed) + ray->plane.y *
		cos(ray->rotation_speed);
}
