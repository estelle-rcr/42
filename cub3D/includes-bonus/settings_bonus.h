/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:00:38 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/30 16:10:56 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_BONUS_H
# define SETTINGS_BONUS_H

# define MAP_CHARSET		"01234567NSEW"
# define PLAY_CHARSET		"0234567NSEW"
# define DIR_CHARSET		"NSEW"
# define SPRITE_CHARSET		"234567"
# define WALKABLE_CHARSET 	"034567"
# define NB_SETTINGS		8
# define NB_TEXT		20
# define MOVE_SPEED		0.2
# define ROTATION_SPEED		0.033

# define MAP_GROUND 		0x00CECECE
# define MAP_WALL 		0x09961608
# define MAP_SPRITES 		0x000000FF
# define MAP_PLAYER 		0x0000FF00
# define PLAYER_LIFE 		50
# define KEYS_TO_FIND 		2
# define BARREL 		4
# define LIGHT_TEXT 		"./textures/greenlight.xpm"
# define LIGHT 			5
# define FOOD_TEXT 		"./textures/food.xpm"
# define FOOD 			6
# define IVY_TEXT	 	"./textures/ivy.xpm"
# define IVY 			7
# define KEY_PU_TEXT 		"./textures/Key_playground.xpm"
# define KEY_PU 		8
# define T_DEFAULT_TEXT 	"./textures/empty.xpm"
# define T_DEFAULT 		9

# define HUD_D_TEXT 		"./textures/HUD_design.xpm"
# define HUD_D 			10
# define MP_HUD_TEXT 		"./textures/mp.xpm"
# define MP_HUD 		11
# define KEY_HUD_TEXT 		"./textures/HUD_key_found.xpm"
# define KEY_HUD 		12
# define HUD_1_TEXT 		"./textures/HUD_1.xpm"
# define HUD_1 			13
# define HUD_5_TEXT 		"./textures/HUD_5.xpm"
# define HUD_5 			14
# define HUD_0_TEXT 		"./textures/HUD_0.xpm"
# define HUD_0 			15

# define FLOOR_TEXT 		"./textures/grass.xpm"
# define FLOOR 			16
# define CEIL_TEXT 		"./textures/metal.xpm"
# define CEIL 			17
# define WIN_TEXT 		"./textures/win.xpm"
# define WIN 			18
# define LOSE_TEXT 		"./textures/loose.xpm"
# define LOSE 			19

#endif
