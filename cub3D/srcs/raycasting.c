/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:19:48 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/07 01:16:57 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	cast_rays(t_game *game)
{
	game->ray.x = 0;
	while (game->ray.x < game->set.res.x)
	{
		init_ray(&game->ray);
		stepsidedist(game);
		color_column(game);
		game->sprite.zbuffer[game->ray.x] = game->ray.perp_wall_dist;
		game->ray.x++;
	}

}

void	stepsidedist(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map_x) \ * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - ray->pos.x) \ * ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (ray->pos.y - ray->map_y) \ * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - ray->pos.y) \ * ray->delta_dist.y;
	}
	increment_loop(ray);
}

void	increment_loop(t_ray *ray)
