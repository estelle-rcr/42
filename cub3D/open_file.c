/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:25:49 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/26 00:23:44 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_settings	init_set(void)
{
	t_settings 	settings;

	settings.fd = -1;
	settings.res.x = 0;
	settings.res.y = 0;
	settings.no_texture = 0;
	settings.so_texture = 0;
	settings.we_texture = 0;
	settings.ea_texture = 0;
	settings.s_texture = 0;
	settings.f_color = -1;
	settings.c_color = -1;
	settings.map = 0;
	settings.map_width = 0;
	settings.map_height = 0;
	return (settings);
}

int	check_extension(char *file, char *type)
{
	int i;
	int j;
	int len;

	len = ft_strlen(type);
	j = 1;
	i = ft_strlen(file);
	while (file[i - j] == type[len - j] && type[len - j])
	{
			j++;
			if (j == len)
				return (1);
	}
	return (0);
}

int	open_file(char *file)
{
	int	fd;

	if (!check_extension(file, ".cub"))
		return (print_err_msg(ERR_EXTENSION));
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
		return (print_err_msg(ERR_OPENING_DIR));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_err_msg(ERR_OPENING_FILE));
	return (fd);
}

int		is_whitespace(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (!ft_isspace(str[i]))
			return (0);
	return (1);
}

int	read_file(char *file)
{
	char 		*line;
	t_settings	set;
	int 			ret;

	set = init_set();
	if ((set.fd = open_file(file)) == 0)
		return (0);
	while ((ret = get_next_line(set.fd, &line)) >= 0)
	{
		if (ret == -1)
			return (print_err_msg(ERR_GNL));
		if (*line && !is_whitespace(line))
		{
			if (!parse_file(line, &set))
				exit(0);
		}
		free(line);
		if (ret == 1)
			line = 0;
	}
	close(set.fd);
//	if (!check_map(&set))
//		exit (0);
	return (1);
}

int	check_map(t_settings *set)
{
	if (!is_valid_map(set))
	{
		if (set->map)
            free_tab(set->map);
		free(set);
		return (print_err_msg(ERR_INVALID_MAP));
	}
    if (!get_player_position(set))
	{
		if (set->map)
            free_tab(set->map);
		free(set);
		return (0);
	}
	if (!all_params(set))
	{
		if (set->map)
            free_tab(set->map);
		free(set);
		return (print_err_msg(ERR_MISSING_PARAMS));
	}
	return (1);
}
