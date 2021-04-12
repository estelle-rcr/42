/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_text_cf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:17:24 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/13 01:16:46 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_textured_cf(t_game *game, t_ray *ray, t_cf_data *cf)
{
	int			y;
	int 		x;
	int			h;

	y = -1;
	h = game->set.res.y;
	ft_bzero(cf, sizeof(t_cf_data));				//enough for pitch and pos_z ?
	while (++y < h)						// / 2 ?
	{
		setup_additionnal_text(game, ray, cf, y);
		x = -1;
		while (++x < game->set.res.x)
		{
			cf->cell_x = (int)(cf->floor.x);
			cf->cell_y = (int)(cf->floor.y);
			cf->tx = (int)(game->textures[5].width * (cf->floor.x -
						cf->cell_x)) & (game->textures[5].width - 1);
			cf->ty = (int)(game->textures[5].height * (cf->floor.y -
						cf->cell_y)) & (game->textures[5].height - 1);
			cf->floor.x += cf->floor_step.x;
			cf->floor.y += cf->floor_step.y;
			game->img.addr[y * game->img.line_length / 4 + x] =
				game->textures[5].addr[cf->ty *
				game->textures[game->wall.txt_dir].line_length / 4
				+ cf->tx];
			game->img.addr[(h - y - 1) * game->img.line_length / 4 + x] =
				game->textures[6].addr[cf->ty *
				game->textures[game->wall.txt_dir].line_length / 4
				+ cf->tx];
		}
	}
}

void	setup_additionnal_text(t_game *game, t_ray *ray, t_cf_data *cf, int i)
{
	int			is_floor;
	int			h;
	int			w;

	h = game->set.res.y;
	w = game->set.res.x;
	is_floor = (i > h / 2 + cf->pitch);
	cf->ray_dir_0.x = ray->dir.x - ray->plane.x;
	cf->ray_dir_0.y = ray->dir.y - ray->plane.y;
	cf->ray_dir_1.x = ray->dir.x + ray->plane.x;
	cf->ray_dir_1.y = ray->dir.y + ray->plane.y;
	cf->p = is_floor ? i - h / 2 - cf->pitch : 2 - i + cf->pitch;
	cf->cam_z = is_floor ? (0.5 * h + cf->pos_z) : (0.5 * h - cf->pos_z);
//	cf->pos_z = 0.5 * h;
//	cf->row_dist = cf->pos_z / cf->p;
	cf->row_dist = cf->cam_z / cf->p;
	cf->floor_step.x = cf->row_dist * (cf->ray_dir_1.x - cf->ray_dir_0.x)
						/ w;
	cf->floor_step.y = cf->row_dist * (cf->ray_dir_1.y - cf->ray_dir_0.y)
						/ w;
	cf->floor.x = ray->pos.x * cf->row_dist * cf->ray_dir_0.x;
	cf->floor.y = ray->pos.y * cf->row_dist * cf->ray_dir_0.y;
}
