/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_add_sprites.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 15:24:18 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/30 17:30:32 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_textures_bonus(t_game *game)
{
	load_more_textures(game);
	game->cf.ceil_txt = CEIL_TEXT;
	load_add_sprites(game, game->cf.ceil_txt, CEIL);
	game->cf.floor_txt = FLOOR_TEXT;
	load_add_sprites(game, game->cf.floor_txt, FLOOR);
	game->adds.light = LIGHT_TEXT;
	load_add_sprites(game, game->adds.light, LIGHT);
	game->adds.food = FOOD_TEXT;
	load_add_sprites(game, game->adds.food, FOOD);
	game->adds.key_pu = KEY_PU_TEXT;
	load_add_sprites(game, game->adds.key_pu, KEY_PU);
	game->adds.ivy = IVY_TEXT;
	load_add_sprites(game, game->adds.ivy, IVY);
	game->adds.hud = HUD_D_TEXT;
	load_add_sprites(game, game->adds.hud, HUD_D);
	game->adds.gun_hud = MP_HUD_TEXT;
	load_add_sprites(game, game->adds.gun_hud, MP_HUD);
	game->adds.key_hud = KEY_HUD_TEXT;
	load_add_sprites(game, game->adds.key_hud, KEY_HUD);
	game->adds.hud_1 = HUD_1_TEXT;
	load_add_sprites(game, game->adds.hud_1, HUD_1);
	game->adds.hud_5 = HUD_5_TEXT;
	load_add_sprites(game, game->adds.hud_5, HUD_5);
	game->adds.hud_0 = HUD_0_TEXT;
	load_add_sprites(game, game->adds.hud_0, HUD_0);
}

void	load_more_textures(t_game *game)
{
	game->adds.t_default = T_DEFAULT_TEXT;
	load_add_sprites(game, game->adds.t_default, T_DEFAULT);
	game->adds.win = WIN_TEXT;
	load_add_sprites(game, game->adds.win, WIN);
	game->adds.lose = LOSE_TEXT;
	load_add_sprites(game, game->adds.lose, LOSE);
}

int		find_sprite_nb(t_game *game, int x, int y)
{
	int sp_nb;

	sp_nb = 0;
	if (ft_strchr(SPRITE_CHARSET, game->set.map[x][y]))
		sp_nb = (int)game->set.map[x][y] - '0' + 2;
	return (sp_nb);
}

int		filter_sprite_bg(int color)
{
	if (color == 10821783 || color == 9961608 || color == 65361 ||
		color == 65363 || color == 10229654 || color == 1285807 ||
		color == 0)
		return (1);
	return (0);
}

int		check_sprite(t_game *game, int y)
{
	int	new_y;

	new_y = y;
	if ((y + (int)game->player.pitch) < (int)game->set.res.y && y +
		(int)game->player.pitch > 0)
		new_y = y + (int)game->player.pitch;
	return (new_y);
}
