/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:48:07 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/21 21:20:55 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	create_bmp_header(t_game *game, int fd)
{
	t_fileheader	fileheader;
	int				img_size;

	img_size = (int)game->set.res.x * (int)game->set.res.y *
				game->img.bpp / 8;
	ft_bzero(&fileheader, sizeof(t_fileheader));
	fileheader.signature[0] = 'B';
	fileheader.signature[1] = 'M';
	fileheader.filesize = sizeof(t_fileheader) - 2 + img_size;
	fileheader.fileoffset = sizeof(t_fileheader) - 2;
	fileheader.reserved = 0;
	fileheader.bitmapinfoheader.dibheadersize =
		sizeof(fileheader.bitmapinfoheader);
	fileheader.bitmapinfoheader.width = (int)game->set.res.x;
	fileheader.bitmapinfoheader.height = (int)game->set.res.y;
	fileheader.bitmapinfoheader.planes = 1;
	fileheader.bitmapinfoheader.bitsperpixel = game->img.bpp;
	fileheader.bitmapinfoheader.compression = 0;
	fileheader.bitmapinfoheader.imagesize = img_size;
	fileheader.bitmapinfoheader.ypixelpermeter = 0x130B;
	fileheader.bitmapinfoheader.xpixelpermeter = 0x130B;
	fileheader.bitmapinfoheader.numcolorspallette = 0;
	fileheader.bitmapinfoheader.mostimpcolor = 0;
	write(fd, &fileheader, 2);
	write(fd, (char*)(&fileheader) + 4, sizeof(t_fileheader) - 4);
}

int		screenshot(t_game *game)
{
	int	fd;
	int	x;
	int	y;

	if ((fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0777)) == -1)
		return (ERROR_OPEN_BMP);
	create_bmp_header(game, fd);
	y = (int)game->set.res.y;
	while (y >= 0)
	{
		x = 0;
		while (x < game->set.res.x)
		{
			write(fd, &game->img.addr[y * game->img.line_length / 4 + x], 4);
			x++;
		}
		y--;
	}
	if (close(fd) == -1)
	{
		exit_game(game);
		return (ERROR_CLOSE_BMP);
	}
	exit_game(game);
	exit(1);
}
