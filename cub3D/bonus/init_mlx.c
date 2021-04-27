/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:47:30 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/21 21:15:00 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "../minilibx-linux/mlx_int.h"

int	create_mlx_win(t_game *game)
{
	int	x;
	int y;

	mlx_get_screen_size(game->mlx, &x, &y);
	if (game->set.res.x > x)
		game->set.res.x = x;
	if (game->set.res.y > y)
		game->set.res.y = y;
	game->win = mlx_new_window(game->mlx, game->set.res.x, game->set.res.y,
				"Cub3D");
	if (!game->win)
		return (ERROR_INIT_MLX_WIN);
	return (1);
}

int	my_mlx_new_img(void *mlx, t_img_data *img, int x, int y)
{
	img->img = mlx_new_image(mlx, x, y);
	if (!img->img)
		return (print_err_msg(ERROR_IMG_MLX));
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
											&img->endian);
	return (1);
}

int	run_mlx(t_game *game)
{
	if (!(game->mlx = mlx_init()))
		return (ERROR_INIT_MLX);
	if (!create_mlx_win(game))
		return (0);
	if (!my_mlx_new_img(game->mlx, &game->img, game->set.res.x,
						game->set.res.y))
		return (0);
	if (!init_game(game))
		return (0);
	if (!load_texture(game) || !load_textures_bonus(game))
		return (0);
	if (game->save == 1)
		cast_rays(game);
	else
	{
		mlx_hook(game->win, ClientMessage, 1L << 17, &exit_game, game);
		mlx_hook(game->win, KeyPress, 1L << 0, &handle_keypress, game);
		mlx_hook(game->win, KeyRelease, 1L << 1, &handle_keyrelease, game);
		mlx_loop_hook(game->mlx, &cast_rays, game);
		mlx_loop(game->mlx);
	}
	exit_game(game);
	return (1);
}

    //((t_xvar*)(game->mlx))->      clean mlx leaks
