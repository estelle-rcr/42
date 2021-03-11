/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cpy_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:46:11 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/09 18:49:28 by erecuero         ###   ########.fr       */
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

char	*replace_tabs(char *line)
{
	int		i;
	int		j;
	int		len;
	char	*line_dup;

	i = -1;
	while (line && line[++i])
	{
		if (line[i] == '\t')
		{
			len = ft_strlen(line) + 4;
			if (!(line_dup = malloc(sizeof(char) * len + 1)))
				return (NULL);
			line_dup = ft_strdup(line);
			j = i;
			while (j < i + 4)
				line_dup[j++] = ' ';
			free(line);
			line = line_dup;
		}
	}
	return (line);
}

char	*ft_strdup_fill(const char *s1, int len)
{
	char	*s2;
	int		i;

	i = 0;
	if (!(s2 = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s1 && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	while (s2 && s2[i] && i <= len)
		s2[i++] = ' ';
	s2[i] = '\0';
	return (s2);
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
	while (tab && i < set->map_height && set->map && (*set->map))
	{
		// tab[i++] = ft_strdup_fill(*set->map, set->map_width);
		tab[i++] = ft_strdup(*set->map);
		set->map++;
	}
// if (!(tab[i] = ft_strdup_fill(line, set->map_width)))
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
