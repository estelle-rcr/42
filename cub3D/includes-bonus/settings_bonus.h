/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:00:38 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/27 22:32:38 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_BONUS_H
# define SETTINGS_BONUS_H

# define MAP_CHARSET	"01234567NSEW"
# define PLAY_CHARSET	"0234567NSEW"
# define DIR_CHARSET	"NSEW"
# define SPRITE_CHARSET "234567"
# define WALKABLE_CHARSET "034567"
# define NB_SETTINGS	8
# define NB_TEXT		13

# define MAP_GROUND 0x00CECECE
# define MAP_WALL 0x09961608
# define MAP_SPRITES 0x000000FF
# define MAP_PLAYER 0x0000FF00

#define	BARREL 4
#define	LIGHT_TEXT "./textures/greenlight.xpm"
#define LIGHT 5
#define FOOD_TEXT "./textures/food.xpm"
#define FOOD 6
#define VAULT_TEXT "./textures/vault.xpm"
#define VAULT 7
#define KEY_PU_TEXT "./textures/Key_playground.xpm"
#define KEY_PU 8
#define GUN_PU_TEXT "./textures/mp_pickup.xpm"
#define GUN_PU 9

#define HUD_D_TEXT "./textures/HUD_design.xpm"
#define HUD_D 10
#define KNIFE_TEXT "./textures/knife.xpm"
#define KNIFE 11
#define MP_HUD_TEXT "./textures/mp.xpm"
#define MP_HUD 12
#define KEY_HUD_TEXT "./textures/HUD_key_playground.xpm"
#define KEY_HUD 13
#define HUD_1_TEXT "./textures/HUD_1.xpm"
#define HUD_1 14
#define HUD_2_TEXT "./textures/HUD_2.xpm"
#define HUD_2 15
#define HUD_9_TEXT "./textures/HUD_9.xpm"
#define HUD_9 16

#define	FLOOR_TEXT "./textures/grass.xpm"
#define FLOOR 18
#define CEIL_TEXT "./textures/metal.xpm"
#define CEIL 19

#endif
