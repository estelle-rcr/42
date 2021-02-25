/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:09:05 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/26 00:13:09 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_params(char **params, t_settings *set)
{
	int		(*settings_fct[NB_SETTINGS + 1])(char**, t_settings*);
	char	**valid_set;
	int i;
	int ret;

	i = 0;
	valid_set = (char *[NB_SETTINGS + 1]) {"R", "NO", "SO", "WE", "EA", "S", "F", "C", 0};
	settings_fct[0] = &check_resolution;
	while (++i <= 5)
		settings_fct[i] = &check_textures;
	settings_fct[6] = &check_colors;
	settings_fct[7] = &check_colors;
	i = -1;
	ret = -1;
	while (valid_set[++i])
		if (ft_strcmp(params[0], valid_set[i]) == 0)
			ret = settings_fct[i](params, set);
	if (ret == -1)
		return (print_err_msg(ERR_CODE_NOT_VALID));
	return (ret);
}

int		all_params(t_settings *set)
{
	if (!set->res.x || !set->res.y || !set->no_texture || !set->so_texture ||
		!set->ea_texture || !set->we_texture || !set->s_texture ||
		set->c_color == -1 || set->f_color == -1)
		return (0);
	return (1);
}

int	parse_file(char *line, t_settings *set)
{
		char		**params;

		if (!all_params(set))
		{
	//		if (!(params = ft_split_whitespaces(line)))
			if (!(params = ft_split(line, ' ')))
				return (print_err_msg(ERR_MALLOC));
			if (!check_params(params, set))
			{
				free_tab(params);
				free(line);
				return (0);
			}
			free_tab(params);
		}
		else if (all_params(set))
		{
			if(!get_map(line, set))
			{
				if (set->map)
            		free_tab(set->map);
				free(line);
				return (0);
			}
		}
		return (1);
}

