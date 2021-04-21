/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:44:54 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/21 18:06:55 by erecuero         ###   ########.fr       */
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

int	comp_null_cells(char **map)
{
	int x;
	int y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
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
		}
	}
	return (1);
}

int	valid_memory(t_settings *set, char **map, int x, int y)
{
	if (x >= 0 && y >= 0 && x < set->map_height && y <
			(int)ft_strlen(map[x]) && map[x][y])
		return (1);
	return (0);
}

int	is_valid_map(t_settings *set, char **map)
{
	int x;
	int y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (valid_memory(set, map, x, y + 1) &&
				!valid_cells(map[x][y], map[x][y + 1]))
				return (0);
			else if (valid_memory(set, map, x, y - 1) &&
						!valid_cells(map[x][y], map[x][y - 1]))
				return (0);
			else if (valid_memory(set, map, x + 1, y) && map[x + 1][y]
						&& !valid_cells(map[x][y], map[x + 1][y]))
				return (0);
			else if (x > 0 && valid_memory(set, map, x - 1, y) &&
					!valid_cells(map[x][y], map[x - 1][y]))
				return (0);
		}
	}
	return (comp_null_cells(map));
}

int	check_map(t_settings *set)
{
	if (!is_valid_map(set, set->map))
	{
		exit_free_settings(set);
		return (print_err_msg(ERR_INVALID_MAP));
	}
	if (!get_start_position(set))
	{
		exit_free_settings(set);
		return (0);
	}
	if (!all_params(set))
	{
		exit_free_settings(set);
		return (print_err_msg(ERR_MISSING_PARAMS));
	}
	return (1);
}
