/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:31:08 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/13 01:18:35 by erecuero         ###   ########.fr       */
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

// si sprite == 2 => walkable, si sprite == 3 non walkable

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

/* BONUS
void	look_up_down(t_game *game, t_cf_data *cf)
{
		if (game->cf.pitch > 0)
		{
			if ((game->cf.pitch - 100 * game->ray.move_speed) > 0)
				game->cf.pitch = game->cf.pitch - 100 * game->ray.move_speed;
			else
				game->cf.pitch = 0;
		}
		if (game->cf.pitch < 0)
		{
			if ((game->cf.pitch + 100 * game->ray.move_speed) > 0)
				game->cf.pitch = game->cf.pitch + 100 * game->ray.move_speed;
			else
				game->cf.pitch = 0;
		}
		move_jump_crouch(game, cf);
}

void	move_jump_crouch(t_game *game, t_cf_data *cf)
{
	if (game->cf.pos_z > 0)
	{
		if ((game->cf.pos_z - 100 * game->ray.move_speed) > 0)
			game->cf.pitch = game->cf.pos_z - 100 * game->ray.move_speed;
		else
			game->cf.pitch = 0;
	}
	if (game->cf.pos_z < 0)
	{
		if ((game->cf.pos_z + 100 * game->ray.move_speed) > 0)
			game->cf.pos_z = game->cf.pos_z + 100 * game->ray.move_speed;
		else
			game->cf.pos_z = 0;
	}
}
*/
