/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 22:26:19 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/01 22:56:50 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

double	normalize_angle(double *ray_angle)
{
	*ray_angle =  fmod(*ray_angle, 2 * M_PI);
	if (*ray_angle < 0)
		*ray_angle = (2 * M_PI) + *ray_angle;
	return (*ray_angle);
}

double	distance_btw_points(double x1, double y1, double x2, double y2)
{
	return(sqrt(((x2 -x1) * (x2 -x1)) + ((y2 - y1) * (y2 - y1))));
}

void	set_axis(t_axis *point, float x, float y)
{
	point->x = x;
	point->y = y;
}
