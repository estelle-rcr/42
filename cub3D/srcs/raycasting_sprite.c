/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:37:23 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/09 20:55:39 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	setup_distance_order(t_game *game, t_ray *ray)
{
	int	i;

	i = -1;
	while (++i < game->sprite.nb)
	{
		game->sprite.order[i] = i;
		game->sprite.distance[i] = ((ray->pos.x - game->obj[i].x) *
			(ray->pos.x - game->obj[i].x) + (ray->pos.y - game->obj[i].y)
			* (ray->pos.y - game->obj[i].y));
	}
	sort_distance_order(game);
}

void	sort_distance_order(t_game *game)
{
	int	i;
	int j;
	double temp;

	i = -1;
	while (++i < game->sprite.nb)
	{
		j = - 1
		while (++j < game->sprite.nb - 1)
		{
			if (game->sprite.distance[j] < game->sprite.distance[j + 1])
			{
				temp = game->sprite.distance[j];
				game->sprite.distance[j] = game->sprite.distance[j + 1];
				game->sprite.distance[j + 1] = temp;
				temp = game->sprite.order[j];
				game->sprite.order[j] = game->sprite.order[j + 1];
				game->sprite.order[j + 1] = (int)temp;
			}
		}
	}
}

void	setup_sprites(t_game *game, t_ray *ray, t_sprite *sprite, int i)
{
	sprite->s_pos.x = game->obj[sprite->order[i]].x - ray->pos.x;
	sprite->s_pos.y = game->obj[sprite->order[i]].y - ray->pos.y;
	sprite->inv_det = 1.0 / (ray->plane.x * ray->dir.y - ray->dir.x *
						ray->plane.y);
	sprite->transform.x = sprite->inv_det * (ray->dir.y * sprite->s_pos.x
							- ray->dir.x * sprite->s_pos.y);
	sprite->transform.y = sprite->inv_det * (-ray->plane.y * sprite->s_pos.x
							+ ray->plane.x * sprite->s_pos.y);
	sprite->s_screenx = (int)((game->set.res.x / 2) * (1 + sprite->transform.x
							/ sprite->transform.y));
	sprite->s_height = abs((int)game->set.res.y / (sprite->transform.y));
	sprite->s_start.y = -sprite->s_height / 2 + game->set.res.y / 2;
	if (sprite->s_start.y < 0)
		sprite->s_start.y = 0;
	sprite->s_end.y = sprite->s_height / 2 + game->set.res.y / 2;
	if (sprite->s_end.y >= game->set.res.y)
		sprite->s_end.y = game->set.res.y - 1;
	sprite->s_width = abs((int)(game->set.res.y / (sprite->transform.y)));		// error? >> (game->set.res.x / (sprite->transform.x)
	sprite->s_start = -sprite->s_width / 2 + sprite->s_screenx;
	if (sprite->s_start.x < 0)
		sprite->s_start.x = 0;
	sprite->s_end = sprite->s_width / 2 + sprite->s_screenx;
	if (sprite->s_end.x >= game->set.res.x)
		sprite->s_end.x = game->set.res.x - 1;
}

void	loop_draw_sprite(t_game *game, int tex_x, int stripe)
{
	int y;
	int d;
	int tex_y;

	y = game->sprite.s_start.y;
	while (y < game->sprite.s_end.y)
	{
		d = (y) * 256 - game->set.res.y * 128 + game->sprite.s_height 128;
		tex_y = ((d * game->textures[4].height) / game->sprite.s_height) / 256;
		if (game->textures[4].addr[tex_y * game->textures[4].line_length / 4 +
			tex_x] != -16777216)																// if((color & 0x00FFFFFF) != 0)
			game->img.addr[y * game->img.line_length / 4 + stripe] =
				game->textures[4].addr[tex_y * game->textures[4].line_length
				/ 4 + tex_x];
		y++;
	}
}

void	render_sprite(t_game *game)
{
	int	i;
	int	tex_x;
	int stripe;

	setup_distance_order(game, &game->ray);
	while (++i < game->sprite.nb)
	{
		setup_sprites(game, &game->ray, &game->sprite, i);
		stripe = game->sprite.s_start.x;
		while (stripe < game->sprite.s_end.x)
		{
			tex_x = (int)(256 * (stripe - (-game->sprite->s_width / 2 +
				game->sprite.s_screenx)) * game->textures[4].width /
				game->sprite.s_width) / 256;
			if (game->sprite.transform.y > 0 && stripe > 0 && stripe <
				game->set.res.x && game->sprite.transform.y <
				game->sprite.zbuffer[stripe])
				loop_draw_sprite(game, tex_x, stripe);
			stripe++;
		}
	}
}
