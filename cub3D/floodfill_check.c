/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:49:22 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/18 15:30:43 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int flood_fill(char **copy_map, float pos_x, float pos_y)
{
	int	wall;
	int playable;
	int sprite;
	int visited;

	wall = 1;
	playable = 0;
	sprite = 2;
	visited = 9;
	if(copy_map[(int)pos_x][(int)pos_y] == wall || copy_map[(int)pos_x][(int)pos_y] == visited) // wall or already visited = OK, go back
		return (1);                                             
	if(copy_map[(int)pos_x][(int)pos_y] != playable || copy_map[(int)pos_x][(int)pos_y] != sprite ) // error should be raised = not OK because not playable
		return (0);
	copy_map[(int)pos_x][(int)pos_y] = 9; // marked the position as visited
	if (!flood_fill(copy_map, pos_x + 1, pos_y))  // then I can either go South
		return (0);	
	if (!flood_fill(copy_map, pos_x - 1, pos_y))  // or North
		return (0);
	if (!flood_fill(copy_map, pos_x, pos_y + 1))  // or East
		return (0);
	if (!flood_fill(copy_map, pos_x, pos_y - 1))  // or West
		return (0);
	return (1);
}