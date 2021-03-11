/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_tabs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:36:53 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/11 19:44:09 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*replace_tabs(char *line)
{
	int		i;

	i = -1;
	while (line && line[++i])
	{
		if (line[i] == '\t')
		{
			line = dup_space(line);
		}
	}
	return (line);
}

char	*dup_space(char *line)
{
	int		j;
	char	*line_dup;

	if (!(line_dup = malloc(sizeof(char) * (ft_strlen(line) + 4 + 1))))
		return (NULL);
	line_dup[ft_strlen(line) + 4] = '\0';
	j = 0;
	while (line[j] && line[j] != '\t')
	{
		line_dup[j] = line[j];
		j++;
	}
	add_spaces(&line_dup[j], 4);
	while (line[j++])
		line_dup[j + 3] = line[j];
//	free(line);
	return (line_dup);
}

void	add_spaces(char *s, int i)
{
	int j;

	j = 0;
	while (j < i)
		s[j++] = ' ';
}
