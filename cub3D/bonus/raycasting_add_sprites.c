/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_add_sprites.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:24:18 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/27 22:37:59 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	load_add_sprites(t_game *game, char *text, int text_nb)
{
	if (!(game->textures[text_nb].img = mlx_xpm_file_to_image(game->mlx,
		text, &(game->textures[text_nb].width),
		&(game->textures[text_nb].height))))
		return (exit_textures(game));
	game->textures[text_nb].addr = (int *)mlx_get_data_addr(game->textures[text_nb].img,
		&game->textures[text_nb].bpp, &game->textures[text_nb].line_length,
		&game->textures[text_nb].endian);
	return (1);
}

int	load_textures_bonus(t_game *game)
{
	game->cf.ceil_txt = CEIL_TEXT;
	load_add_sprites(game, game->cf.ceil_txt, CEIL);
	game->cf.floor_txt = FLOOR_TEXT;
	load_add_sprites(game, game->cf.floor_txt, FLOOR);
	game->adds.light = LIGHT_TEXT;
	load_add_sprites(game, game->adds.light, LIGHT);
	game->adds.food = FOOD_TEXT;
	load_add_sprites(game, game->adds.food, FOOD);
	game->adds.vault = VAULT_TEXT;
	load_add_sprites(game, game->adds.vault, VAULT);
	game->adds.key_pu = KEY_PU_TEXT;
	load_add_sprites(game, game->adds.key_pu, KEY_PU);
	game->adds.hud = HUD_D_TEXT;
	load_add_sprites(game, game->adds.hud, HUD_D);
	game->adds.gun_hud = MP_HUD_TEXT;
	load_add_sprites(game, game->adds.gun_hud, MP_HUD);
	return (1);
}

int		find_sprite_nb(t_game *game, int x, int y)
{
	int sp_nb;

	sp_nb = 0;
	if (ft_strchr(SPRITE_CHARSET, game->set.map[x][y]))
		sp_nb = (int)game->set.map[x][y] - '0' + 2;
	return (sp_nb);
}

int	filter_sprite_bg(int color)
{
	if (color == 10821783 || color == 9961608 || color == 65361 || color == 65363 ||
		color == 10229654 || color == 1285807 || color == 0)
		return (1);
	return (0);
}

int		check_sprite(t_game *game, int y)
{
	int	new_y;

	new_y = y;
	if((y + (int)game->player.pitch) < (int)game->set.res.y)
		new_y = y + (int)game->player.pitch;
	return (new_y);
}