/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:20:46 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/26 00:26:05 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map(char *s)
{
	while (s && *s)
    {
		if (!ft_strchr(MAP_CHARSET, *s) && !ft_isspace(*s))
			return (0);
        s++;
    }
	return (1);
}

/*
** For floodfill algo to check the map, replace is_valid_map(set) line XX by :
** declare : char **copy_map;
** copy_map = ft_strdup(set->map);
** then place after get_player_position:
** flood_fill(copy_map, set->player_start->x, set->player_start->y);
** then free(copy_map);
*/

int	get_map(char *line, t_settings *set)
{
	if (!is_map(line))
        return (print_err_msg(ERR_NOT_MAP_LINE));
    (void)set;
    if (!copy_map(line, set))
        return (0);
    return (1);
}

int copy_map(char *line, t_settings *set)
{
    char    **tab;
    int     width;
    int i;

    i = 0;
    if (!(tab = malloc(sizeof(char *) * (set->map_height++ + 1))))
        return (print_err_msg(ERR_MALLOC));
    tab[set->map_height] = 0;
    width = ft_strlen(line);
    if (width > set->map_width)
        set->map_width = width;
    while(tab && tab[i] && set->map && (*set->map))
    {
        tab[i++] = ft_strdup((*set->map));
    }
    if (!(tab[i] = ft_strdup(line)))
        return (print_err_msg(ERR_MALLOC));
    if (set->map)
        free_tab(set->map);
    set->map = tab;
    return (1);
}

int is_valid_map(t_settings *set)
{
    int x;
    int y;

    x = -1;
    while (set->map[++x])
    {
        y = -1;
        while (set->map[x][++y])
        {
            if (set->map[x][y+1] && !valid_cells(set->map[x][y], set->map[x][y+1]))
                return (0);
            else if (set->map[x][y-1] && !valid_cells(set->map[x][y], set->map[x][y-1]))
                 return (0);
            else if (set->map[x+1] && set->map[x+1][y] && !valid_cells(set->map[x][y], set->map[x+1][y]))
                 return (0);
            else if (x > 0 && set->map[x-1] && set->map[x-1][y] && !valid_cells(set->map[x][y], set->map[x-1][y]))
                 return (0);
        }
    }
    return (1);
}

int valid_cells(char case1, char case2)
{
    if (ft_strchr(PLAY_CHARSET, (int)case1) && ft_strchr(MAP_CHARSET, (int)case2))
        return (1);
    else if (!ft_strchr(PLAY_CHARSET, (int)case1))
        return (1);
    else
        return (0);
}

int get_player_position(t_settings *set)
{
    int x;
    int y;
    int nb_player;

    nb_player = 0;
    x = -1;
    while (set->map[++x])
    {
        y = -1;
        while (set->map[x][++y])
        {
            if (ft_strchr(DIR_CHARSET, set->map[x][y]))
            {
                set->start_pos.player_x = (float)x;
                set->start_pos.player_y = (float)y;
                set->player_dir = set->map[x][y];
                set->map[x][y] = 0;
                nb_player++;
            }
        }
    }
    if (nb_player != 1)
        return (print_err_msg(ERR_PLAYER_COUNT));
    return (0);
}
