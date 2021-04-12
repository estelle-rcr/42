/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:49:34 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/12 16:54:25 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "cub3d.h"
# include "libft/includes/libft.h"

typedef struct		s_bitmapinfoheader
{
	uint32_t dibheadersize;
	uint32_t width;
	uint32_t height;
	uint16_t planes;
	uint16_t bitsperpixel;
	uint32_t compression;
	uint32_t imagesize;
	uint32_t ypixelpermeter;
	uint32_t xpixelpermeter;
	uint32_t numcolorspallette;
	uint32_t mostimpcolor;
}						t_bitmapinfoheader;

typedef	struct		s_fileheader
{
	uint8_t signature[2];
	uint32_t filesize;
	uint32_t reserved;
	uint32_t fileoffset;
	t_bitmapinfoheader bitmapinfoheader;
}						t_fileheader;

int		screenshot(t_game *game);
void	create_bmp_header(t_game *game, int fd);

#endif
