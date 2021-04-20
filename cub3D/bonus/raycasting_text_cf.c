/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_text_cf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:17:24 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/18 22:02:50 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_textured_cf(t_game *game, t_ray *ray)
{
	int			y;
	int 		x;
	int			h;

	y = -1;
	h = game->set.res.y;
	ft_bzero(&game->cf, sizeof(t_cf_data));
	while (++y < h)						// / 2 ?
	{
		setup_additionnal_text(game, ray, &game->cf, y);
		x = -1;
		while (++x < game->set.res.x)
		{
			game->cf.cell_x = (int)(game->cf.floor.x);
			game->cf.cell_y = (int)(game->cf.floor.y);
			game->cf.tx = (int)(game->text_cf[0].width * (game->cf.floor.x -
						game->cf.cell_x)) & (game->text_cf[0].width - 1);
			game->cf.ty = (int)(game->text_cf[0].height * (game->cf.floor.y -
						game->cf.cell_y)) & (game->text_cf[0].height - 1);
			game->cf.floor.x += game->cf.floor_step.x;
			game->cf.floor.y += game->cf.floor_step.y;
			game->img.addr[y * game->img.line_length / 4 + x] =
				game->text_cf[0].addr[game->cf.ty *
				game->textures[game->wall.txt_dir].line_length / 4
				+ game->cf.tx];
			game->img.addr[(h - y - 1) * game->img.line_length / 4 + x] =
				game->text_cf[1].addr[game->cf.ty *
				game->textures[game->wall.txt_dir].line_length / 4
				+ game->cf.tx];
		}
	}
}

void	setup_additionnal_text(t_game *game, t_ray *ray, int i)
{
	int			is_floor;
	int			h;
	int			w;

	h = game->set.res.y;
	w = game->set.res.x;
	is_floor = (i > h / 2 + game->cf.pitch);
	game->cf.ray_dir_0.x = ray->dir.x - ray->plane.x;
	game->cf.ray_dir_0.y = ray->dir.y - ray->plane.y;
	game->cf.ray_dir_1.x = ray->dir.x + ray->plane.x;
	game->cf.ray_dir_1.y = ray->dir.y + ray->plane.y;
	game->cf.p = is_floor ? i - h / 2 - game->cf.pitch : 2 - i + game->cf.pitch;
	game->cf.cam_z = is_floor ? (0.5 * h + game->cf.pos_z) : (0.5 * h - game->cf.pos_z);
//	game->cf.pos_z = 0.5 * h;
//	game->cf.row_dist = game->cf.pos_z / game->cf.p;
	game->cf.row_dist = game->cf.cam_z / game->cf.p;
	game->cf.floor_step.x = game->cf.row_dist * (game->cf.ray_dir_1.x - game->cf.ray_dir_0.x)
						/ w;
	game->cf.floor_step.y = game->cf.row_dist * (game->cf.ray_dir_1.y - game->cf.ray_dir_0.y)
						/ w;
	game->cf.floor.x = ray->pos.x * game->cf.row_dist * game->cf.ray_dir_0.x;
	game->cf.floor.y = ray->pos.y * game->cf.row_dist * game->cf.ray_dir_0.y;
}

int	load_texture_cf(t_game *game)
{
	game->cf.ceil_txt = CEIL;
	game->cf.floor_txt = FLOOR;
	if (!(game->text_cf[0].img = mlx_xpm_file_to_image(game->mlx,
		game->cf.ceil_txt, &(game->text_cf[0].width),
		&(game->text_cf[0].height))))
		return (ERROR_TXT_LOAD_IMG);
	if (!(game->text_cf[1].img = mlx_xpm_file_to_image(game->mlx,
		game->cf.floor_txt, &(game->text_cf[1].width),
		&(game->text_cf[1].height))))
		return (ERROR_TXT_LOAD_IMG);
	game->text_cf[0].addr = (int *)mlx_get_data_addr(game->text_cf[0].img,
		&game->text_cf[0].bpp, &game->text_cf[0].line_length,
		&game->text_cf[0].endian);
	game->text_cf[1].addr = (int *)mlx_get_data_addr(game->text_cf[1].img,
		&game->text_cf[1].bpp, &game->text_cf[1].line_length,
		&game->text_cf[1].endian);
	return (1);
}
