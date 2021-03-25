/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cpy_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:46:11 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/24 14:25:12 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map(char *s)
{
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
	int		width;
	int		i;

	i = 0;
	set->map_height++;
	if (!(tab = malloc(sizeof(char *) * (set->map_height + 1))))
		return (print_err_msg(ERR_MALLOC));
	tab[set->map_height] = 0;
	width = ft_strlen(line);
	if (width > set->map_width)
		set->map_width = width;
	while (tab && i < set->map_height && set->map && set->map[i])
	{
		tab[i] = ft_strdup(set->map[i]);
		i++;
	}
	if (!(tab[i] = ft_strdup(line)))
	{
		free_tab(tab);
		return (print_err_msg(ERR_MALLOC));
	}
	free_map(set->map);
	set->map = tab;
	return (1);
}

int		get_map(char *line, t_settings *set)
{
	if (!is_map(line))
		return (print_err_msg(ERR_NOT_MAP_LINE));
	if (!(line = replace_tabs(line)))
		return (print_err_msg(ERR_MALLOC));
	if (!copy_map(line, set))
		return (0);
	return (1);
}
