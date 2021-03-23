/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:47:30 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/23 12:34:54 by erecuero         ###   ########.fr       */
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

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
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

int		my_mlx_new_img(void *mlx, t_img_data *img, int x, int y)
{
	img->img = mlx_new_image(mlx, x, y);
	if (!img->img)
		return(print_err_msg(ERROR_IMG_MLX));
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length, &img->endian);
	return (1);
}



//	game->img.addr[x * 4 + 4 * game->img.line_length * y] = 0x0000FF00;
//	render_background(&game->img, 0x00FFFFFF);



int	run_mlx(t_game *game, int save)
{
//	init_game(game);

	(void)save;
	if (!(game->mlx = mlx_init()))
		return (ERROR_INIT_MLX);
	if (!create_mlx_win(game))
		return (0);
	if (!my_mlx_new_img(game->mlx, &game->img, game->set.res.x, game->set.res.y))
		return (0);
	game->set.player_pos.x *= MAP_SIZE;
	game->set.player_pos.y *= MAP_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_loop_hook(game->mlx, &render, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, &handle_keyrelease, game);
	mlx_loop(game->mlx);
	exit_game(game);
	return (1);
}

int	render(t_game *game)
{
	if (game->win != NULL)
	{
		draw_map(game, &game->set);
		draw_player(game);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	}
	return (1);
}

void	render_background(t_img_data *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 510)
	{
		j = 0;
		while (j < 620)
		{
			my_mlx_pixel_put(img, j++, i, color);
		}
		++i;
	}
}