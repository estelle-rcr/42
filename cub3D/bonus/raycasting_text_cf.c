/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_text_cf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:17:24 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/27 21:14:01 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_textured_cf(t_game *game, t_ray *ray)
{
	int			y;
	int 		x;
	int			h;

	h = (int)game->set.res.y;
//	y = h / 2 + 1;
	y = 0;
	init_cf_textures(game);
	while (++y < h)
	{
		setup_additionnal_text(game, ray, y);
		x = 0;
		while (++x < game->set.res.x)
		{
			setup_cf(game);
			if (game->cf.is_floor)
				game->img.addr[y * game->img.line_length / 4 + x] =
					add_shade_cf(game->cf.row_dist,
					game->textures[FLOOR].addr[game->cf.ty *
					game->textures[FLOOR].line_length / 4 + game->cf.tx]);
			else
				game->img.addr[y * game->img.line_length / 4 + x] =
					add_shade_cf(game->cf.row_dist,
					game->textures[CEIL].addr[game->cf.ty *
					game->textures[CEIL].line_length / 4 + game->cf.tx]);
		}
	}
}

void	init_cf_textures(t_game *game)
{
	ft_bzero(&game->cf, sizeof(t_cf_data));
	game->cf.ray_dir_0.x = 0;
	game->cf.ray_dir_0.y = 0;
	game->cf.ray_dir_1.x = 0;
	game->cf.ray_dir_1.y = 0;
	game->cf.floor.x = 0;
	game->cf.floor.y = 0;
	game->cf.floor_step.x = 0;
	game->cf.floor_step.y = 0;
}

void	setup_additionnal_text(t_game *game, t_ray *ray, int y)
{
	int			h;
	int			w;

	h = game->set.res.y;
	w = game->set.res.x;
	game->cf.is_floor = ((int)y > (int)h / 2 + game->player.pitch);
	game->cf.ray_dir_0.x = ray->dir.x - ray->plane.x;
	game->cf.ray_dir_0.y = ray->dir.y - ray->plane.y;
	game->cf.ray_dir_1.x = ray->dir.x + ray->plane.x;
	game->cf.ray_dir_1.y = ray->dir.y + ray->plane.y;
	game->cf.p = game->cf.is_floor ? (int)y - (int)h / 2 - game->player.pitch :
					(int)h / 2 - (int)y + game->player.pitch;
	game->cf.pos_z = 0.5 * h;
	game->cf.row_dist = game->cf.pos_z / game->cf.p;
	game->cf.floor_step.x = game->cf.row_dist * (game->cf.ray_dir_1.x -
							game->cf.ray_dir_0.x) / w;
	game->cf.floor_step.y = game->cf.row_dist * (game->cf.ray_dir_1.y -
							game->cf.ray_dir_0.y) / w;
	game->cf.floor.x = ray->pos.x + game->cf.row_dist * game->cf.ray_dir_0.x;
	game->cf.floor.y = ray->pos.y + game->cf.row_dist * game->cf.ray_dir_0.y;
}

void	setup_cf(t_game *game)
{
	game->cf.cell_x = (int)(game->cf.floor.x);
	game->cf.cell_y = (int)(game->cf.floor.y);
	game->cf.tx = (int)(game->textures[FLOOR].width * (game->cf.floor.x -
				game->cf.cell_x)) & (game->textures[FLOOR].width - 1);
	game->cf.ty = (int)(game->textures[FLOOR].height * (game->cf.floor.y -
				game->cf.cell_y)) & (game->textures[FLOOR].height - 1);
	game->cf.floor.x += game->cf.floor_step.x;
	game->cf.floor.y += game->cf.floor_step.y;
}
