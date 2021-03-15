/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero@student.42.fr <erecuero>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:47:30 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/15 17:24:37 by erecuero@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/X.h>
#include <X11/keysym.h>

void	init_game(t_game *game)
{
	game->mlx_ptr = 0;
	game->win_ptr = 0;
//	game->rays = 0;
//	game->sprites = 0;
}

void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		create_mlx_win(t_game *game)
{
	int	x;
	int y;

	mlx_get_screen_size(game->mlx_ptr, &x, &y);
	if (game->set.res.x > x)
		game->set.res.x = x;
	if (game->set.res.y > y)
		game->set.res.y = y;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->set.res.x, game->set.res.y, "Cub3D");
	if (!game->win_ptr)
	{
		free(game->win_ptr);
		return (ERROR_INIT_MLX_WIN);		
	}
	return (1);
}

/*
int		my_mlx_new_img(void *mlx, t_img_data *img, int x, int y)
{
	img->img = mlx_new_image(mlx, x, y);
	if (!img->img)
		return(print_err_msg(ERROR_IMG_MLX));
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	return (1);
}
*/

/*
void	draw_rect(t_img_data *img, t_axis pos, t_axis res, int color)
{
	float	x;
	float	y;

	x = 0;
	while (x < res.x)
	{
		y = 0;
		while (y < res.y)
		{
			my_mlx_pixel_put(img, pos.x + x, pos.y + y, color);
			y++;
		}
		x++;
	}
}*/


//	if (!my_mlx_new_img(game->mlx, &game->img, game->set.res.x, game->set.res.y))
//			return (0);

int	run_mlx(t_game *game, int save)
{
//	init_game(game);

	(void)save;
	if (!(game->mlx_ptr = mlx_init()))
		return (ERROR_INIT_MLX);
	if (!create_mlx_win(game))
		return (0);
//	
//	mlx_hook(game->win, 02, 1L<<0, render, &game);

	mlx_loop_hook(game->mlx_ptr, &render, game);

	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);

	mlx_loop(game->mlx_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	return (1);
}

int	render(t_game *game)
{
	int x;
	int y;

	x = -1;
	y = -1;
	if (game->win_ptr != NULL)
	{
	//	mlx_pixel_put(game->mlx_ptr, game->win_ptr, game->set.res.x / 2, game->set.res.y / 2, 0x00FF0000);
		game->img.img = mlx_new_image(game->mlx_ptr, game->set.res.x, game->set.res.y);
		game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	//	my_mlx_pixel_put(&game->img, 5, 5, 0x00FF0000);
		while (game->set.map[++x])
		{
			while (game->set.map[x][++y])
			{
				print_map(game, game->set.map[x][y], y, x);
			}
		}
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.img, 0, 0);
	}
	return (0);
}

void	print_map(t_game *game, char p, int y, int x)
{
//	int max_x;
//	int max_y;
	int color;

	if (p == '1')
		color = 0x00FFFFFF;
	else if (p == 'N' || p == 'S' || p == 'W' || p == 'E')
		color = 0x0000FF00;
	else if (p == '2')
		color = 0x000000FF;
	else
		color = 0x00FF0000;
	my_mlx_pixel_put(&game->img, y, x, color);
	/*
	x *= 10;
	max_x = x + 10;
	y *= 10;
	max_y = y + 10;
	while (x < max_x)
	{
		while (y < max_y)
		{
			my_mlx_pixel_put(&game->img, x, y, color);
			y++;	
		}
		x++;
	}*/
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		game->win_ptr = NULL;		
	}
	return (0);
}