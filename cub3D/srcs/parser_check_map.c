/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:44:54 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/08 23:47:10 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_cells(char case1, char case2)
{
	if (ft_strchr(PLAY_CHARSET, (int)case1) && ft_strchr(MAP_CHARSET,
		(int)case2))
		return (1);
	else if (!ft_strchr(PLAY_CHARSET, (int)case1))
		return (1);
	else
		return (0);
}

int	comp_null_cells(char **map, int x, int y)
{
	if (ft_strchr(PLAY_CHARSET, map[x][y]) && !map[x][y + 1])
		return (0);
	else if (ft_strchr(PLAY_CHARSET, map[x][y]) && !map[x][y - 1])
		return (0);
	else if (ft_strchr(PLAY_CHARSET, map[x][y]) && (!map[x + 1] ||
				!map[x + 1][y]))
		return (0);
	else if (ft_strchr(PLAY_CHARSET, map[x][y]) && (!map[x - 1] ||
				!map[x - 1][y]))
		return (0);
	else
		return (1);
}

int	is_valid_map(char **map)
{
	int x;
	int y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y + 1] && !valid_cells(map[x][y], map[x][y + 1]))
				return (0);
			else if (map[x][y - 1] && !valid_cells(map[x][y], map[x][y - 1]))
				return (0);
			else if (map[x + 1] && map[x + 1][y] && !valid_cells(map[x][y],
						map[x + 1][y]))
				return (0);
			else if (x > 0 && map[x - 1] && map[x - 1][y] &&
					!valid_cells(map[x][y], map[x - 1][y]))
				return (0);
			else if (!comp_null_cells(map, x, y))
				return (0);
		}
	}
	return (1);
}

int	get_player_position(t_settings *set)
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
				set->start_pos.x = (float)x;
				set->start_pos.y = (float)y;
				set->player_dir = set->map[x][y];
				set->map[x][y] = '0';
				nb_player++;
			}
		}
	}
	if (nb_player != 1)
		return (print_err_msg(ERR_PLAYER_COUNT));
	return (1);
}

int	check_map(t_settings *set)
{
	if (!is_valid_map(set->map))
	{
		if (set->map)
			free_map(set->map);
		return (print_err_msg(ERR_INVALID_MAP));
	}
	if (!get_player_position(set))
	{
		if (set->map)
			free_map(set->map);
		return (0);
	}
	if (!all_params(set))
	{
		if (set->map)
			free_map(set->map);
		return (print_err_msg(ERR_MISSING_PARAMS));
	}
	return (1);
}
