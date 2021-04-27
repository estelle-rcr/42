/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:18:44 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/27 20:49:07 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		add_shade(double distance, int trgb)
{
	int r;
	int g;
	int b;
	
	if (distance < 1.0)
		return (trgb);
	r = ((int)((0xFF0000 & trgb) >> 16) / (distance));
	g = ((int)((0x00FF00 & trgb) >> 8) / (distance));
	b = ((int)(0x0000FF & trgb) / (distance));
	return (0 << 24 | r << 16 | g << 8 | b);
}

int		add_shade_cf(double distance, int trgb)
{
	int r;
	int g;
	int b;
	
	if (distance < 0.0)
		return ((0x000000 & trgb));
	r = ((int)((0xFF0000 & trgb) >> 16) / (distance));
	g = ((int)((0x00FF00 & trgb) >> 8) / (distance));
	b = ((int)(0x0000FF & trgb) / (distance));
	return (0 << 24 | r << 16 | g << 8 | b);
}

int	hit_screen(t_game *game, int x, int y)
{
	if (x >= 0 && y >= 0 && x <= (int)game->set.res.x &&  y <= (int)game->set.res.y)
		return (0);
	return (1);
}
