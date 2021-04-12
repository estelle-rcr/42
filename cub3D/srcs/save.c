/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:11:35 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/12 19:56:58 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	screenshot(t_game *game)
{
	int	fd;
	int	x;
	int	y;


	fd = open("./image.bmp", O_CREAT | O_RDWR);
	if (fd == -1)
		return (ERROR_OPEN_BMP);
	create_bmp_header(game, fd);
	y = 0;
	while (y <= game->set.res.y)
	{
		x = 0;
		while (x <= game->set.res.x)
		{
			write(fd, &game->img.addr[y * game->img.line_length / 4 + x], 4);
			x++;
		}
		y++;
	}
	system("chmod 777 image.bmp");
	if (close(fd) == -1)
		return (ERROR_CLOSE_BMP);
	exit_game(game); // need a specific exit / clean ?
	exit(0);
}

void	create_bmp_header(t_game *game, int fd)
{
	t_fileheader	fileheader;
	int				img_size;

	img_size = game->set.res.x * game->set.res.y * game->img.bpp / 8;
	ft_bzero(&fileheader, sizeof(t_fileheader));
	fileheader.signature[0] = 'B';
	fileheader.signature[1] = 'M';
	fileheader.filesize = sizeof(t_fileheader) - 2 + img_size;
	fileheader.fileoffset = sizeof(t_fileheader) - 2;
	fileheader.reserved = 0;
	fileheader.bitmapinfoheader.dibheadersize =
		sizeof(fileheader.bitmapinfoheader);
	fileheader.bitmapinfoheader.width = game->set.res.x;
	fileheader.bitmapinfoheader.height = game->set.res.y;
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
