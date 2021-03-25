/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_setup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 00:58:49 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/25 00:59:50 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	init_ray(t_ray *ray, float ray_angle)
{
	ray->angle = ray_angle;
	ray->axis_hit.x = 0;
	ray->axis_hit.y = 0;
	ray->distance = 0;
	//...
}

void	update_player(t_game *game)
{
	float move_step;
	t_axis next;
	t_axis step;
	
	game->player.rotation_angle += game->player.turn_dir * game->player.rotation_speed;
	move_step = game->player.walk_dir * game->player.move_speed;
	step.x = cos(game->player.rotation_angle); // +game->player.direction_angle
	step.y = sin(game->player.rotation_angle); // +game->player.direction_angle
    next.x = game->player.pos.x + (step.x * move_step);
	next.y = game->player.pos.y + (step.y * move_step);
	if (!hit_wall(game->set.map, (int)(next.x / MAP_SIZE), (int)(next.y / MAP_SIZE)))
	{
		game->player.pos.x = next.x;
		game->player.pos.y = next.y;
		draw_player(game);
	}
	//game->player.rotation_angle = normalize_angle(game->player.rotation_angle);
}

void	render_background(t_game *game)
{
	t_axis	ceil_start;
	t_axis	ceil_end;
	t_axis	floor_start;
	t_axis	floor_end;

	ceil_start.x = 0;
	ceil_start.y = 0;
	ceil_end.x = game->set.res.x;
	ceil_end.y = game->set.res.y / 2;
	floor_start.x = 1;
	floor_start.y = game->set.res.y / 2;
	floor_end.x = game->set.res.y;
	floor_end.y = game->set.res.x;
	draw_rect(game, ceil_start, ceil_end, game->set.c_color);
	draw_rect(game, floor_start, floor_end, game->set.f_color);
}