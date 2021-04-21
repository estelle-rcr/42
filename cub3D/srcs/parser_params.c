/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:49:56 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/20 14:43:19 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_resolution(char **params, t_settings *set)
{
	int x;
	int y;

	if (set->res.x || set->res.y)
		return (print_err_msg(ERR_RES_ALREADY_ADDED));
	else if (params[3] != NULL || !params[1] || !params[2])
		return (print_err_msg(ERR_RES_INPUTS));
	else if (!(x = atoi_res(params[1])))
		return (print_err_msg(ERR_RES_FORMAT));
	else if (!(y = atoi_res(params[2])))
		return (print_err_msg(ERR_RES_FORMAT));
	else if (x <= 0 || y <= 0)
		return (print_err_msg(ERR_NEGATIVE_RES));
	else
	{
		set->res.x = x;
		set->res.y = y;
		return (1);
	}
}

int	check_textures(char **params, t_settings *set)
{
	int		i;
	char	**valid_set;
	char	***textures_set;

	if (params[2] != NULL || !params[1])
		return (print_err_msg(ERR_TEX_INPUTS));
	if (!(ft_strnstr(params[1], "./", 2)) || ft_strlen(params[1]) <= 2)
		return (print_err_msg(ERR_TEX_FORMAT));
	valid_set = (char *[NB_SETTINGS - 2]) {"NO", "SO", "WE", "EA", "S", 0};
	textures_set = (char **[NB_SETTINGS - 2]) {&set->no_txt, &set->so_txt,
					&set->we_txt, &set->ea_txt, &set->s_txt, 0};
	i = -1;
	while (valid_set[++i])
	{
		if (ft_strcmp(params[0], valid_set[i]) == 0)
		{
			if ((*textures_set)[i] != NULL)
				return (print_err_msg(ERR_TEX_ALREADY_ADDED));
			else
				(*textures_set)[i] = ft_strdup(params[1]);
		}
	}
	return (1);
}

int	check_colors(char **params, t_settings *set)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	if (params[2] != NULL || !params[1])
		return (print_err_msg(ERR_COLOR_INPUTS));
	if (!check_atoi_colors(params[1]))
		return (print_err_msg(ERR_COLOR_FORMAT));
	if (!(colors = ft_split(params[1], ',')))
		return (print_err_msg(ERR_MALLOC));
	if (!colors[0] || !colors[1] || !colors[2])
		return (print_err_msg(ERR_COLOR_FORMAT));
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_tab(colors);
	if ((*params)[0] == 'F' && set->f_color == -1)
		set->f_color = create_trgb(0, r, g, b);
	else if ((*params)[0] == 'C' && set->c_color == -1)
		set->c_color = create_trgb(0, r, g, b);
	else
		return (print_err_msg(ERR_COLOR_ALREADY_ADDED));
	return (1);
}
