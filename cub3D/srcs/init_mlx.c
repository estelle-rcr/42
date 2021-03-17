/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:47:30 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/17 23:37:21 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/X.h>
#include <X11/keysym.h>

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

void	draw_rect(t_game *game, t_axis pos, int color)
{
	float	i;
	float	j;

	i = 0;
	while (i < MAP_SIZE)
	{
		j = 0;
		while (j < MAP_SIZE)
		{
			if ((pos.x + i < game->set.res.x) && (pos.y + j < game->set.res.y) && (pos.x + i > 0) && (pos.y + j > 0))
				my_mlx_pixel_put(&game->img, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
	}
}

//	game->img.addr[x * 4 + 4 * game->img.line_length * y] = 0x0000FF00;
//	render_background(&game->img, 0x00FFFFFF);

void	draw_map(t_game *game, t_settings *set, int color)
{
	int	i;
	int	j;
	t_axis pos;

	i = 0;
	(void)pos;
	while (set->map[i])
	{
		j = 0;
		while (set->map[i][j])
		{
			pos.x = j * MAP_SIZE;
			pos.y = i * MAP_SIZE;
			if (set->map[i][j] == '0')
				draw_rect(game, pos, 0x00FFFFFF);
			else if (set->map[i][j] == '2')
				draw_rect(game, pos, 0x000000FF);				
			else
				draw_rect(game, pos, color);		
			j++;
		}
		i++;
	}
	pos.x = game->set.start_pos.x * MAP_SIZE;
	pos.y = game->set.start_pos.y * MAP_SIZE;
	draw_rect(game, pos, 0x0000FF00);
}

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
//		draw_rect(game, game->set.start_pos, 0x000000FF);
		draw_map(game, &game->set, 0x00FF0000);
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	}
	return (1);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ARROW_UP || keycode == W_KEY)
		game->set.start_pos.y -= 1;
	else if (keycode == ARROW_DOWN || keycode == S_KEY)
		game->set.start_pos.y += 1;
	else if (keycode == ARROW_LEFT || keycode == A_KEY)
		game->set.start_pos.x -= 1;
	else if (keycode == ARROW_RIGHT || keycode == D_KEY)
		game->set.start_pos.x += 1;
	else if (keycode == ESCAPE)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	return (1);
}

int	handle_keyrelease(int keycode, t_game *game)
{
	(void)game;
	printf("keyrelease: %d\n", keycode);
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