/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:55:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/30 12:46:38 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		init_game(t_game *game)
{
	game->player.forward = 0;
	game->player.back = 0;
	game->player.left = 0;
	game->player.right = 0;
	game->player.rotation_left = 0;
	game->player.rotation_right = 0;
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
	game->ray.pos.x = (double)game->set.start_pos.y + 0.5;
	game->ray.pos.y = (double)game->set.start_pos.x + 0.5;
	init_ray_direction(game);
	if (!(init_sprite(game)))
		return (0);
	if (!(game->sprite.zbuffer = (double *)malloc(sizeof(double) *
			game->set.res.x)))
		return (print_err_msg(ERR_MALLOC));
	return (1);
}

void	init_ray_direction(t_game *game)
{
	game->ray.dir.x = 0;
	game->ray.dir.y = 0;
	game->ray.plane.x = 0;
	game->ray.plane.y = 0;
	if (game->set.player_dir == 'N')
	{
		game->ray.dir.x = -1;
		game->ray.plane.y = 0.66;
	}
	if (game->set.player_dir == 'S')
	{
		game->ray.dir.x = 1;
		game->ray.plane.y = -0.66;
	}
	if (game->set.player_dir == 'W')
	{
		game->ray.dir.y = -1;
		game->ray.plane.x = -0.66;
	}
	if (game->set.player_dir == 'E')
	{
		game->ray.dir.y = 1;
		game->ray.plane.x = 0.66;
	}
}

void	init_ray(t_game *game)
{
	game->ray.hit = 0;
	game->ray.perp_wall_dist = 0;
	game->ray.camerax = 2 * game->ray.x / (double)game->set.res.x - 1;
	game->ray.ray_dir.x = game->ray.dir.x + game->ray.plane.x *
		game->ray.camerax;
	game->ray.ray_dir.y = game->ray.dir.y + game->ray.plane.y *
		game->ray.camerax;
	game->ray.map_x = (int)game->ray.pos.x;
	game->ray.map_y = (int)game->ray.pos.y;
	game->ray.move_speed = MOVE_SPEED;
	game->ray.rotation_speed = ROTATION_SPEED * 1.8;
	if (game->ray.ray_dir.y == 0)
		game->ray.delta_dist.x = 0;
	else if (game->ray.ray_dir.x == 0)
		game->ray.delta_dist.x = 1;
	else
		game->ray.delta_dist.x = sqrt(1 + (game->ray.ray_dir.y *
			game->ray.ray_dir.y) / (game->ray.ray_dir.x * game->ray.ray_dir.x));
	if (game->ray.ray_dir.x == 0)
		game->ray.delta_dist.y = 0;
	else if (game->ray.ray_dir.y == 0)
		game->ray.delta_dist.y = 1;
	else
		game->ray.delta_dist.y = sqrt(1 + (game->ray.ray_dir.x *
			game->ray.ray_dir.x) / (game->ray.ray_dir.y * game->ray.ray_dir.y));
}

void	init_obj(t_game *game)
{
	int	i;
	int	j;
	int	nb;

	i = -1;
	nb = 0;
	while (++i < game->set.map_height)
	{
		j = -1;
		while (++j < (int)ft_strlen(game->set.map[i]))
		{
			if (game->set.map[i][j] == '2')
			{
				game->obj[nb].x = (double)i + 0.5;
				game->obj[nb].y = (double)j + 0.5;
				nb++;
			}
		}
	}
}

int		init_sprite(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->set.map_height)
	{
		j = -1;
		while (++j < (int)ft_strlen(game->set.map[i]))
		{
			if (game->set.map[i][j] == '2')
				game->sprite.nb++;
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
	init_obj(game);
	return (1);
}
