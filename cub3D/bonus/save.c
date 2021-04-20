/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:11:35 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/18 21:29:28 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
int	screenshot(t_game *game)
{
	int	fd;
	int	x;
	int	y;

	mlx_loop_end(game->mlx);
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
	{
		exit_game(game);
		return (ERROR_CLOSE_BMP);		
	}
	exit_game(game);
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
*/

void	create_bmp_header(t_game *game, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * game->set.res.x * game->set.res.y;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &game->set.res.x, 4);
	write(fd, &game->set.res.y, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &game->img.bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

int	screenshot(t_game *game)
{
	int	fd;
	int	x;
	int	y;

	y = game->set.res.y;
	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		return (ERROR_OPEN_BMP);
	create_bmp_header(game, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < game->set.res.x)
		{
			write(fd, &game->img.addr[y * game->img.line_length / 4 + x],
				4);
			x++;
		}
		y--;
	}
	system("chmod 777 image.bmp");
	mlx_loop_end(game->mlx);
	exit_game(game);
	return (0);
}


