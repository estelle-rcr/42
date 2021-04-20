/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:19:48 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/18 21:17:51 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cast_rays(t_game *game)
{
	game->ray.x = 0;
	while (game->ray.x < game->set.res.x)
	{
		init_ray(game);
		step_side_dist(game, &game->ray);
		draw_color(game, &game->ray);
		game->sprite.zbuffer[game->ray.x] = game->ray.perp_wall_dist;
		game->ray.x++;
	}
	render_sprite(game);
	if (game->save)
		screenshot(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	move_forward_back(&game->ray, &game->player, game->set.map);
	move_left_right(&game->ray, &game->player, game->set.map);
	rotation_left_right(&game->ray, &game->player);
	//swap ?
	return (1);
}

void	step_side_dist(t_game *game, t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (ray->pos.y - ray->map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - ray->pos.y) * ray->delta_dist.y;
	}
	perform_dda_loop(game, ray);
}

void	perform_dda_loop(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->set.map[ray->map_x][ray->map_y] == '1')			// sort de la map et inverse x / Y ? valid_memory(&game->set, game->set.map, ray->map_x, ray->map_y) &&
			ray->hit = 1;
	}
	create_wall_stripes(game, ray);
}

void	create_wall_stripes(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ((double)ray->map_x - ray->pos.x + (1 -
								(double)ray->step_x) / 2) / ray->ray_dir.x;
	else
		ray->perp_wall_dist = ((double)ray->map_y - ray->pos.y + (1 -
								(double)ray->step_y) / 2) / ray->ray_dir.y;
	ray->line_height = (int)(game->set.res.y / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + game->set.res.y / 2;			// ray->draw_start = -ray->line_height / 2 + game->set.res.y / 2 + game->cf.pitch + (game->cf.posZ / ray->perp_wall_dist);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + game->set.res.y / 2;				// + game->cf.pitch + (game->cf.posZ / ray->perp_wall_dist);
	if (ray->draw_end >= game->set.res.y || ray->draw_end < 0)
		ray->draw_end = game->set.res.y - 1;
}

void	draw_color(t_game *game, t_ray *ray)
{
	int j;
	int i;

	j = -1;
	ray->draw_end = game->set.res.y - ray->draw_start;
	i = ray->draw_end;
    while (++j < ray->draw_start)
		game->img.addr[j * game->img.line_length / 4 + ray->x] =
			game->set.c_color;
	if (j <= ray->draw_end)
		setup_wall_textures(game, j - 1);
	j = i;
    while (++j < game->set.res.y)
		game->img.addr[j * game->img.line_length / 4 + ray->x] =
			game->set.f_color;
}
