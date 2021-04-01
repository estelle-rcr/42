/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:07:52 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/01 22:56:10 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	init_game(t_game *game)
{
	if(!(game->rays = malloc(sizeof(t_ray) * game->set.res.x)))
		return (print_err_msg(ERR_MALLOC));
	game->dst_projection_plane = (game->set.res.x / 2) / tan(degToRad(FOV / 2));
//	game->sprites = 0;
	return (0);
}

void	init_player(t_game *game)
{
	game->player.pos.x = game->set.start_pos.x;
	game->player.pos.y = game->set.start_pos.y;
	game->player.turn_dir = 0;
	game->player.walk_dir = 0;
	game->player.move_speed = MOVE_SPEED;							// modulate w/ screen size
	game->player.rotation_speed = ROTATION_SPEED * (M_PI / 180);	// modulate w/ screen size
	//game->player.move_speed = game->set.res.x * MOVE_SPEED / game->screen_size.x;
	//game->player.rotation_speed = ((game->set.res.x * ROTATION_SPEED / game->screen_size.y) * M_PI) / 180;
	if (game->set.player_dir == 'N')
		game->player.rotation_angle = M_PI + M_PI / 2;
	else if (game->set.player_dir == 'S')
		game->player.rotation_angle = M_PI / 2;
	else if (game->set.player_dir == 'W')
		game->player.rotation_angle = M_PI;
	else if (game->set.player_dir == 'E')
		game->player.rotation_angle = 0;
}

void	init_ray(t_ray *ray, float ray_angle)
{
	ray->angle = ray_angle;
    ray->wall_hit.x = 0;
	ray->wall_hit.y = 0;
	ray->distance = 0;
	ray->wall_content = 0;
	ray->facing_down = (ray_angle > 0 && ray_angle < M_PI);
	ray->facing_left = (ray_angle > M_PI / 2 && ray_angle < 1.5 * M_PI);
	ray->north_wall = 0;
	ray->south_wall = 0;
	ray->west_wall = 0;
	ray->east_wall = 0;
	ray->hit_vertical = 0;
	ray->hit_horizontal = 0;
}
