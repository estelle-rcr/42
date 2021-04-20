/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:09:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/19 23:54:43 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_game(t_game *game)
{
	if (!exit_free_mlx_components(game))
	{
		if (game->mlx)
			free(game->mlx);
		exit (0);
	}
	exit_free_settings(&game->set);
	if (game->sprite.zbuffer)
		free(game->sprite.zbuffer);
	if (game->obj)
		free(game->obj);
	if (game->sprite.order)
		free(game->sprite.order);
	if (game->sprite.distance)
		free(game->sprite.distance);
	if (game->mlx)
		free(game->mlx);
	exit (1);
}

int 	exit_free_mlx_components(t_game *game)
{
	int i;

	if (game->mlx && game->img.img)
		if (!mlx_destroy_image(game->mlx, game->img.img))
			return (ERR_MLX_DESTROY);
	i = -1;
	while (++i < 5)
	{
		if (game->mlx && game->textures[i].img)
			if(!mlx_destroy_image(game->mlx, game->textures[i].img))
				return (ERR_MLX_DESTROY);
	}
	if (game->mlx && game->win)
		if (!(mlx_destroy_window(game->mlx, game->win)))
			return (ERR_MLX_DESTROY);
	if (game->mlx)
		if (!(mlx_destroy_display(game->mlx)))
			return (ERR_MLX_DESTROY);
	game->win = NULL;
	return (1);
}

void	exit_free_settings(t_settings *set)
{
	if (set->no_txt)
		free(set->no_txt);
	if (set->so_txt)
		free(set->so_txt);
	if (set->ea_txt)
		free(set->ea_txt);
	if (set->we_txt)
		free(set->we_txt);
	if (set->s_txt)
		free(set->s_txt);
	if (set->map && *set->map)
		free_tab(set->map);
}