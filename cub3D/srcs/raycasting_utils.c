/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:28:39 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/02 11:29:58 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_axis(t_axis *point, float x, float y)
{
	point->x = x;
	point->y = y;
}


int is_wall(t_game *game, int axis_x, int axis_y)
{
	char **map;
	int			x;
	int			y;

	map = game->set.map;
	x = (int)axis_x;
	y = (int)axis_y;
	if (x < 0 || y < 0 || x >= game->set.res.x - 1 || y >= game->set.res.y - 1 || y > game->set.map_height || x > (int)ft_strlen(map[y]))
		return (1);
	else
		return (map[y][x]);
}
