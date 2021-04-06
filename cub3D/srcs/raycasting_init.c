/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:55:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/07 01:05:18 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	init_game(t_game *game)
{


}

int		init_ray(t_ray *ray, t_axis	*res)
{
	ray->hit = 0;
	ray->perp_wall_dist = 0;
	ray->camerax = 2 * ray.x / (double)res->x - 1;
	ray->ray_dir.x = ray->dir.x + ray->plan.x * \ ray->camerax;
	ray->ray_dir.y = ray->dir.y + ray->plan.y * \ ray->camerax;
	ray->map_x = (int) ray->pos.x;
	ray->map_y = (int) ray->pos.y;
	ray->move_speed = 0.1;
	ray->rotation_speed = 0.033 * 1.8;

}

void	init_texture(t_game *game)
{

}

void	load_texture(t_game *game)
{
	if (!(game->north_txt.img = mlx_xpm_file_to_image(game->mlx, game->set.no_texture, &game->north_txt.width, &game->north_txt.height)))
		return (ERROR_TXT_LOAD_IMG);
	//...
	get_texture_addr(game);
}

void	get_texture_addr(t_game	*game)
{
	game->north_txt.addr = (int *)mlx_get_data_addr(game->north_txt.img, &game->north_txt.bpp, &game->north_txt.line_length, &game->north_txt.endian);
	// fail possible sur addr ?
	//...
}
