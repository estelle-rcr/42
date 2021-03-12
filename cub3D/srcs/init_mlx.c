/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:47:30 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/12 17:07:33 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = 0;
	game->win = 0;
//	game->rays = 0;
//	game->sprites = 0;
}

void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int		my_mlx_new_img(void *mlx, t_img_data *img, int x, int y)
{
	img->img = mlx_new_image(mlx, x, y);
	if (!img->img)
		return(print_err_msg(ERROR_IMG_MLX));
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (1);
}

int		create_mlx_win(t_game *game)
{
	int	x;
	int y;

	mlx_get_screen_size(game->mlx, &x, &y);
	if (game->set.res.x > x)
		game->set.res.x = x;
	if (game->set.res.y > y)
		game->set.res.y = y;
	game->win = mlx_new_window(game->mlx, game->set.res.x, game->set.res.y, "Cub3D");
	if (!game->win)
		return (ERROR_INIT_MLX_WIN);
	return (1);
}

int	run_mlx(t_game *game, int save)
{
//	init_game(game);
//	int x = 500;
//	int y = 500;
	t_axis location;
	
	location.x = 5;
	location.y = 5;
	(void)save;
	if (!(game->mlx = mlx_init()))
		return (ERROR_INIT_MLX);
	if (!create_mlx_win(game))
		return (0);
	if (!my_mlx_new_img(game->mlx, &game->img, game->set.res.x, game->set.res.y))
			return (0);
//	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
//	game->img.addr[x * 4 + 4 * game->img.line_length * y] = 0x0000FF00;
	draw_rect(&game->img, location, &game->set, 0x000000FF);
	my_mlx_pixel_put(&game->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_loop(game->mlx);
	return (1);
}

void	draw_rect(t_img_data *img, t_axis location, t_settings *set, int color)
{
	float	x;
	float	y;

	x = 0;
	while (x < set->res.x - 10 )
	{
		y = 0;
		while (y < set->res.y - 10)
		{
			my_mlx_pixel_put(img, location.x + x, location.y + y, color);
			y++;
		}
		x++;
	}
}