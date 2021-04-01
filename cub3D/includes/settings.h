/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:00:38 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/01 23:10:31 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# define MAP_SIZE 10
# define PLAYER_SIZE 5
# define MAP_GROUND 0x00CECECE
# define MAP_WALL 0x00606060
# define MAP_SPRITES 0x000000FF
# define MAP_PLAYER 0x0000FF00
# define MOVE_SPEED 0.1 // school : 0.3
# define ROTATION_SPEED 0.8 // school : 1.5
# define FOV 60

# define WALL_COLOR_N 0x006977A1
# define WALL_COLOR_S 0x004682B4
# define WALL_COLOR_W 0x0048B99A
# define WALL_COLOR_E 0x00B0F2B6
# define WALL_ERROR 0x00000000
#include <stdio.h>

#endif
