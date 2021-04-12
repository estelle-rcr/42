/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:09:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/12 20:51:42 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_game(t_game *game)
{
	exit_free_settings(game);
	if (game->sprite.zbuffer)
		free(game->sprite.zbuffer);
	if (game->obj)
		free(game->obj);
	if (game->sprite.order)
		free(game->sprite.order);
	if (game->sprite.distance)
		free(game->sprite.distance);
	if (!exit_free_mlx_components(game))
	{
		if (game->mlx)
		free(game->mlx);
		exit (0);
	}
	if (game->mlx)
		free(game->mlx);
	return (1);
}

int 	exit_free_mlx_components(t_game *game)
{
	int i;

	if (game->mlx && game->img.img)
		if (!mlx_destroy_image(game->mlx, &game->img.img))
			return (ERR_MLX_DESTROY);
	i = -1;
	while (++i < 5)
	{
		if (game->mlx && game->textures[i].img)
			if(!mlx_destroy_image(game->mlx, &game->textures[i].img))
				return (ERR_MLX_DESTROY);
	}
	if (game->mlx && game->win)
		if (!(mlx_destroy_window(game->mlx, game->win)))
			return (ERR_MLX_DESTROY);
	if (game->mlx)
		if (!(mlx_destroy_display(game->mlx)))
			return (ERR_MLX_DESTROY);
	return (1);
}

void	exit_free_settings(t_game *game)
{
	if (game->set.no_txt)
		free(game->set.no_txt);
	if (game->set.so_txt)
		free(game->set.so_txt);
	if (game->set.ea_txt)
		free(game->set.ea_txt);
	if (game->set.we_txt)
		free(game->set.we_txt);
	if (game->set.s_txt)
		free(game->set.s_txt);
	if (game->set.map && *game->set.map)
		free_map(game->set.map);
