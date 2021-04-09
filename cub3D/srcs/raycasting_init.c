/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:55:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/09 21:08:46 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	init_game(t_game *game)
{
	player->forward = 0;
	player->back = 0;
	player->left = 0;
	player->right = 0;
	player->rotation_left = 0;
	player->rotation_right = 0;
	game->textures[0].img = NULL;
	game->textures[1].img = NULL;
	game->textures[2].img = NULL;
	game->textures[3].img = NULL;
	game->textures[4].img = NULL;
	game->sprite.order = NULL;
	game->sprite.distance = NULL;
	game->sprite.zbuffer = NULL;
	game->sprite.nb = 0;
	game->obj = NULL;
	if (!(init_sprite(game)))
		return (0);
	if (!(game->sprite.zbuffer = (double *)malloc(sizeof(double) *
			game->set.res.x)))
		return (print_err_msg(ERR_MALLOC));
	return (0);
}

void	init_ray(t_game *game, t_ray *ray)
{
	init_ray_direction(&game->set, &game->ray);
	ray->hit = 0;
	ray->perp_wall_dist = 0;
	ray->camerax = 2 * ray.x / (double)game->set.res->x - 1;
	ray->ray_dir.x = ray->dir.x + ray->plane.x * ray->camerax;
	ray->ray_dir.y = ray->dir.y + ray->plane.y * ray->camerax;
	ray->map_x = (int) ray->pos.x;
	ray->map_y = (int) ray->pos.y;
	ray->move_speed = 0.1;
	ray->rotation_speed = 0.033 * 1.8;
	if (ray->ray_dir.y == 0)
		ray->delta_dist.x = 0;
	else if (ray->ray_dir.x == 0)
		ray->delta_dist.x = 1;
	else
		ray->delta_dist.x = sqrt(1 + (ray->ray_dir.y * ray->ray_dir.y)
									/ (ray->ray_dir.x * ray->ray_dir.x));
	if (ray->ray_dir.x == 0)
		ray->delta_dist.y = 0;
	else if (ray->ray_dir.y == 0)
		ray->delta_dist.y = 1;
	else
		ray->delta_dist.y = sqrt(1 + (ray->ray_dir.x * ray->ray_dir.x)
										/ (ray->ray_dir.y * ray->ray_dir.y));
}

void	init_ray_direction(t_settings *set, t_ray *ray)
{
	ray->pos.x = (double)game->set.start_pos.x + 0.5;
	ray->pos.y = (double)game->set.start_pos.y + 0.5;
	ray->dir.x = 0;
	ray->dir.y = 0;
	ray->plane.x = 0;
	ray->plane.y = 0;
	if (set->player_dir == 'N')
	{
		ray->dir.x = -1;
		ray->plane.y = 0.66;
	}
	if (set->player_dir == 'S')
	{
		ray->dir.x = 1;
		ray->plane.y = -0.66;
	}
	if (set->player_dir == 'W')
	{
		ray->dir.y = -1;
		ray->plane.x = -0.66;
	}
	if (set->player_dir == 'E')
	{
		ray->dir.y = 1;
		ray->plane.x = 0.66;
	}
}

void	init_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0 && ray->ray_dir.x < 0)
		game->wall.txt_dir = 0;
	if (ray->side == 0 && ray->ray_dir.x >= 0)
		game->wall.txt_dir = 1;
	if (ray->side == 1 && ray->ray_dir.y < 0)
		game->wall.txt_dir = 2;
	if (ray->side == 1 && ray->ray_dir.y >= 0)
		game->wall.txt_dir = 3;
	if (ray->side == 0)
		game->wall.wall_x -= floor(ray->pos.y + ray->perp_wall_dist
										* ray->ray_dir.y);
	else
		game->wall.wall_x -= floor(ray->pos.x + ray->perp_wall_dist
										* ray->ray_dir.x);
}

int		init_sprite(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->set.map_height)
	{
		j = -1;
		while (++j < ft_strlen(game->set.map[i]))
		{
			if (game->set.map[i][j] == '2')
			{
				game->obj[game->sprite.nb].x = (double)i + 0.5;
				game->obj[game->sprite.nb].y = (double)j + 0.5;
				game->sprite.nb++;
			}
		}
	}
	if (!(game->obj = (t_dblaxis *)malloc(sizeof(t_dblaxis) *
			game->sprite.nb)))
		return (print_err_msg(ERR_MALLOC));
	if (!(game->sprite.order = (int *)malloc(sizeof(int) * game->sprite.nb)))
		return (print_err_msg(ERR_MALLOC));
	if (!(game->sprite.distance = (double *)malloc(sizeof(double) *
			game->sprite.nb)))
		return (print_err_msg(ERR_MALLOC));
	return (1);
}
