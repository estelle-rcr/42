/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:30:11 by erecuero          #+#    #+#             */
/*   Updated: 2021/05/03 14:13:01 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_settings	*init_set(t_settings *set)
{
	set->fd = -1;
	set->res.x = 0;
	set->res.y = 0;
	set->start_pos.x = -1.0;
	set->start_pos.y = -1.0;
	set->player_dir = '0';
	set->no_txt = 0;
	set->so_txt = 0;
	set->we_txt = 0;
	set->ea_txt = 0;
	set->s_txt = 0;
	set->f_color = -1;
	set->c_color = -1;
	set->map = 0;
	set->map_width = 0;
	set->map_height = 0;
	return (set);
}

int			check_extension(char *file, char *type)
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

int			open_file(char *file)
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

int			is_whitespace(char *str)
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

int			read_file(char *file, t_settings *set)
{
	char		*line;
	int			ret;

	init_set(set);
	if ((set->fd = open_file(file)) == 0)
		return (0);
	while ((ret = get_next_line(set->fd, &line)) >= 0)
	{
		if (ret == -1)
			exit(ERR_GNL);
		if (*line && !is_whitespace(line))
		{
			if (!parse_file(line, set))
				return (0);
		}
		free(line);
		if (ret == 0)
			break ;
		line = 0;
	}
	if (close(set->fd) == -1)
		return (ERROR_CLOSE_FILE);
	if (!check_map(set))
		exit(1);
	return (1);
}
