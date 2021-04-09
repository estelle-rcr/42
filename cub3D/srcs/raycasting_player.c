/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:31:08 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/09 21:10:44 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	move_forward_back(t_ray *ray, t_player *player, char **map)
{
	if (player->forward)
	{
		if (map[(int)(ray->pos.x + (ray->dir.x * ray->move_speed))]
			[(int)ray->pos.y] == '0')  // move_speed * 2
			ray->pos.x += ray->dir.x * ray->move_speed;
		if (map[(int)(ray->pos.x)][(int)(ray->pos.y + (ray->dir.y *
			ray->move_speed))] == '0')
			ray->pos.y += ray->dir.y * ray->move_speed;
	}
    if (player->back)
    {
        if (map[(int)(ray->pos.x - (ray->dir.x * ray->move_speed))]
			[(int)ray->pos.y] == '0')  // move_speed * 2
			ray->pos.x -= ray->dir.x * ray->move_speed;
        if (map[(int)(ray->pos.x)][(int)(ray->pos.y - (ray->dir.y *
			ray->move_speed))] == '0')
			ray->pos.y -= ray->dir.y * ray->move_speed;
    }
}

void	move_left_right(t_ray *ray, t_player *player, char **map)
{
	if (player->right)
	{
		if (map[(int)(ray->pos.x + (ray->dir.x * ray->move_speed))]
			[(int)ray->pos.y] == '0')  // move_speed * 2
			ray->pos.x += ray->dir.x * ray->move_speed;
		if (map[(int)(ray->pos.x)][(int)(ray->pos.y - (ray->dir.y *
			ray->move_speed))] == '0')
			ray->pos.y -= ray->dir.y * ray->move_speed;
	}
    if (player->left)
	{
		if (map[(int)(ray->pos.x - (ray->dir.x * ray->move_speed))]
			[(int)ray->pos.y] == '0')  // move_speed * 2
			ray->pos.x -= ray->dir.x * ray->move_speed;
		if (map[(int)(ray->pos.x)][(int)(ray->pos.y + (ray->dir.y *
			ray->move_speed))] == '0')
			ray->pos.y += ray->dir.y * ray->move_speed;
	}
}

void	rotation_left_right(t_ray *ray, t_player *player)
{
    double old_dir_x;
    double old_plane_x;

    if (player->rotation_right)
    {
        old_dir_x = ray->dir.x;
        ray->dir.x = ray->dir.x  * cos(-ray->rotation_speed) - ray->dir.y * sin(-ray->rotation_speed);
        ray->dir.y = old_dir_x * sin(-ray->rotation_speed) + ray->dir.y * cos(-ray->rotation_speed);
        old_plane_x = ray->plane.x;
        ray->plane.x = ray->plane.x * cos(-ray->rotation_speed) - ray->plane.y * sin(-ray->rotation_speed);
        ray->plane.y = old_plane_x * sin(-ray->rotation_speed) + ray->plane.y * cos(-ray->rotation_speed);
    }
    if (player->rotation_left)
    {
        old_dir_x = ray->dir.x;
        ray->dir.x = ray->dir.x  * cos(ray->rotation_speed) - ray->dir.y * sin(ray->rotation_speed); //cos(-ray->rotspeed / 2) ?
        ray->dir.y = old_dir_x * sin(ray->rotation_speed) + ray->dir.y * cos(ray->rotation_speed);
        old_plane_x = ray->plane.x;
        ray->plane.x = ray->plane.x * cos(ray->rotation_speed) - ray->plane.y * sin(ray->rotation_speed);
        ray->plane.y = old_plane_x * sin(ray->rotation_speed) + ray->plane.y * cos(ray->rotation_speed);
    }
}
