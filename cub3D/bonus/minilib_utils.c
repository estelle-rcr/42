/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:18:44 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/21 21:18:23 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		add_shade(double distance, int trgb)
{
	return (trgb | ((int)distance / 255) << 24);
}

void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	int *dst;

	dst = (img->addr + (y * img->line_length + x * (img->bpp / 8)));
	*(unsigned int *)dst = color;
}
