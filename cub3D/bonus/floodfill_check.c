/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:49:22 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/21 21:14:28 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
/*
int	check_map(t_settings *set)
{
    char **copy_map;
    int i;

    i = set->map_height;
    if (!(copy_map = malloc(sizeof(char *) * (set->map_height + 1))))
        return (ERR_MALLOC);
    while (set->map && set->map[--i])
    {
        copy_map[i] = ft_strdup(set->map[i]);
    }
    if (!get_start_position(set))
	{
		if (set->map)
            free_tab(set->map);
		return (0);
	}
    if (!(flood_fill(copy_map, set->start_pos.x , set->start_pos.y)))
    {
    	if (set->map)
            free_tab(set->map);
        free_tab(copy_map);
		return (print_err_msg(ERR_INVALID_MAP));
	}
    free_tab(copy_map);
	if (!all_params(set))
	{
		if (set->map)
            free_tab(set->map);
		return (print_err_msg(ERR_MISSING_PARAMS));
	}
	return (1);
}
*/
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
