/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:09:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/11 20:23:06 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_game *game)
{
	if(!(mlx_destroy_window(game->mlx, game->win)))
		return (0);
	if(!(mlx_destroy_display(game->mlx)))
		return (0);
	return (1);
}