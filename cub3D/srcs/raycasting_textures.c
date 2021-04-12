/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:28:39 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/13 00:03:46 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	set_axis(t_axis *point, float x, float y)
{
	point->x = x;
	point->y = y;
}


int is_wall(t_game *game, int axis_x, int axis_y)
{
	char **map;
	int			x;
	int			y;

	map = game->set.map;
	x = (int)axis_x;
	y = (int)axis_y;
	if (x < 0 || y < 0 || x >= game->set.res.x - 1 || y >= game->set.res.y - 1
        || y > game->set.map_height || x > (int)ft_strlen(map[y]))
		return (1);
	else
		return (map[y][x]);
}*/

int	load_texture(t_game *game)
{
	if (!(game->textures[0].img = mlx_xpm_file_to_image(game->mlx,
		game->set.no_txt, &game->textures[0].width, &game->textures[0].height)))
		return (ERROR_TXT_LOAD_IMG);
	if (!(game->textures[1].img = mlx_xpm_file_to_image(game->mlx,
		game->set.so_txt, &game->textures[1].width, &game->textures[1].height)))
		return (ERROR_TXT_LOAD_IMG);
	if (!(game->textures[2].img = mlx_xpm_file_to_image(game->mlx,
		game->set.we_txt, &game->textures[2].width, &game->textures[2].height)))						// check east and west textures
		return (ERROR_TXT_LOAD_IMG);
	if (!(game->textures[3].img = mlx_xpm_file_to_image(game->mlx,
		game->set.ea_txt, &game->textures[3].width, &game->textures[3].height)))
		return (ERROR_TXT_LOAD_IMG);
	if (!(game->textures[4].img = mlx_xpm_file_to_image(game->mlx,
		game->set.s_txt, &game->textures[4].width, &game->textures[4].height)))
		return (ERROR_TXT_LOAD_IMG);
	get_addr_texture(game);
	return (1);
}

void	get_addr_texture(t_game *game)
{
	game->textures[0].addr = (int *)mlx_get_data_addr(game->textures[0].img,
		&game->textures[0].bpp, &game->textures[0].line_length,
		&game->textures[0].endian);
	game->textures[1].addr = (int *)mlx_get_data_addr(game->textures[1].img,
		&game->textures[1].bpp, &game->textures[1].line_length,
		&game->textures[1].endian);
	game->textures[2].addr = (int *)mlx_get_data_addr(game->textures[2].img,
		&game->textures[2].bpp, &game->textures[2].line_length,
		&game->textures[2].endian);
	game->textures[3].addr = (int *)mlx_get_data_addr(game->textures[3].img,
		&game->textures[3].bpp, &game->textures[3].line_length,
		&game->textures[3].endian);
	game->textures[4].addr = (int *)mlx_get_data_addr(game->textures[4].img,
		&game->textures[4].bpp, &game->textures[4].line_length,
		&game->textures[4].endian);
}

void	setup_wall_textures(t_game *game, t_ray *ray)
{
	init_texture(game, &game->ray);
	game->wall.txt_x = (int)(game->wall.wall_x *
						(double)game->textures[game->wall.txt_dir].width);
	if (ray->side == 0 && ray->ray_dir.x > 0)
		game->wall.txt_x = game->textures[game->wall.txt_dir].width -
							game->wall.txt_x - 1;
	if (ray->side == 1 && ray->ray_dir.y < 0)
		game->wall.txt_x = game->textures[game->wall.txt_dir].width -
							game->wall.txt_x - 1;
	game->wall.step = 1.0 * game->textures[game->wall.txt_dir].height /
						ray->line_height;
	game->wall.txt_pos = (ray->draw_start - game->set.res.y / 2 +
							ray->line_height / 2) * game->wall.step; 		// 	game->wall.txt_pos = (ray->draw_start - game->cf.pitch - (game->cf.posZ / ray->perp_wall_dist) - game->set.res.y / 2 + ray->line_height / 2) * game->wall.step;

}
