/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_RTC.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:21:25 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/17 00:15:33 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int	check_resolution(char **params, t_settings *set)
{
	int x;
	int y;

	if (set->res.x || set->res.y)
		return (print_err_msg(ERR_RES_ALREADY_ADDED));
	else if (params[3] != NULL || !params[1] || !params[2])
		return (print_err_msg(ERR_RES_INPUTS));
	else if (!(x = atoi_res(params[1])) || !(y = atoi_res(params[2])))
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
	char	**valid_set;
	char	**textures_set;
	int 	i;

	if (params[2] != NULL || !params[1])
		return (print_err_msg(ERR_TEX_INPUTS));
	if (!(ft_strnstr(params[1], "./", 2)) || ft_strlen(params[1]) <= 2) // detect at beginning?
		return (print_err_msg(ERR_TEX_FORMAT));
	valid_set = (char *[NB_SETTINGS - 2]) {"NO", "SO", "WE", "EA", "S", 0};
	textures_set = (char *[NB_SETTINGS - 2]) {set->no_texture, set->so_texture, set->we_texture, set->ea_texture, set->s_texture};
	i = -1;
	while(valid_set[++i])
	{
		if (ft_strcmp(params[0], valid_set[i]) == 0)
		{
			if (textures_set[i] != 0)
				return (print_err_msg(ERR_TEX_ALREADY_ADDED));
			else
				textures_set[i] = params[1];
		}
	}
	return (1);
}


int	check_colors(char **params, t_settings *set)
{
	char 	**colors;
	int r;
	int g;
	int b;

	if (params[2] != NULL || !params[1])
		return (print_err_msg(ERR_COLOR_INPUTS));
	if (!check_atoi_colors(params[1]))
		return (print_err_msg(ERR_COLOR_FORMAT));
	if (!(colors = ft_split(params[1], ',')))
		return (print_err_msg(ERR_MALLOC));
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_tab(colors, 3);
	if ((*params)[0] == 'F' && set->f_color == -1)
		set->f_color = create_trgb(0, r, g, b);
	else if ((*params)[0] == 'C' && set->c_color == -1)
		set->c_color = create_trgb(0, r, g, b);
	else
		return (print_err_msg(ERR_COLOR_ALREADY_ADDED));
	return (0);
}
