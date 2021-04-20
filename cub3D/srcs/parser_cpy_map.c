/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cpy_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:46:11 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/19 23:05:44 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map(char *s, t_settings *set)
{
	if (*s)
		set->map_height++;
	while (s && *s)
	{
		if (!ft_strchr(MAP_CHARSET, *s) && !ft_isspace(*s))
			return (0);
		s++;
	}
	return (1);
}

int		copy_map(char *line, t_settings *set)
{
	char	**tab;
	char	**temp;
	int		width;
	int		i;

	i = -1;
	tab = ft_get_file(set->fd, 0);
	while (tab && tab[++i])
		if (!is_map(tab[i], set))
			return (print_err_msg(ERR_NOT_MAP_LINE));	
	if (!(temp = malloc(sizeof(char *) * (set->map_height + 1))))
		return (print_err_msg(ERR_MALLOC));
	i = 0;
	temp[i] = ft_strdup(line);
	i++;
	while (tab && tab[i - 1] && temp && i < set->map_height)
	{
		temp[i] = ft_strdup(tab[i - 1]);
		width = ft_strlen(temp[i++]);
		if (width > set->map_width)
			set->map_width = width;
	}
	temp[set->map_height] = 0;
	free_tab(tab);
	set->map = temp;
	return (1);
}

int		get_map(char *line, t_settings *set)
{
	if (!is_map(line, set))
		return (print_err_msg(ERR_NOT_MAP_LINE));
/*	if (!(line = replace_tabs(line)))
		return (print_err_msg(ERR_MALLOC));*/
	if (!copy_map(line, set))
		return (0);
	return (1);
}

int	get_start_position(t_settings *set)
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
				set->start_pos.x = (float)y;
				set->start_pos.y = (float)x;
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
