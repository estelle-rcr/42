/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:09:05 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/10 23:28:12 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_file(char *file)
{
	char *line;
	char **params;
	t_settings *set;
	int ret;

	init_set(set);
	if ((set->fd = open_file(file)) == 0)
		return (0);
	while ((ret = get_next_line(set->fd, &line)) >= 0)
	{
		if (!(params = ft_split(line, " ")))
			return (print_err_msg(ERR_MALLOC));
		if (!check_params(params, set))
		{
			free_tab(params, count_elements(params));
			free(line);
			return (0);
		}
		free_tab(params, count_elements(params));
		free(line);
		if (ret == 1)
			line = 0;
	}
	if (ret == -1)
		return (print_err_msg(ERR_GNL));
	if (is_missing_params(set))
		return (print_err_msg(ERR_MISSING_PARAMS));
	close(fd);
	return (1);
}

void	init_set(t_settings *set)
{
	t_settings settings;

	settings.fd = -1;
	res.x = 0;
	res.y = 0;
	settings.no_texture = 0;
	settings.so_texture = 0;
	settings.we_texture = 0;
	settings.ea_texture = 0;
	settings.s_texture = 0;
	settings.f_texture = 0;
	set = &settings;
}

int	check_params(char **params, t_settings *set)
{
	int		(*settings_fct[NB_SETTINGS])(char**, t_settings*);
	char	**valid_set;
	int i;
	int ret;

	i = 0;
	valid_set = (char *[NB_SETTINGS + 1]) {"R", "NO", "SO", "WE", "EA", "S", "F", "C", NULL};
	settings_fct[0] = &check_resolution;
	while (++i <= 5)
		settings_fct[i] = &check_textures;
	settings_fct[6] = &check_colors;
	settings_fct[7] = &check_colors;
	i = -1;
	ret = 0;
	while(valid_set[++i])
		if (ft_strcmp(params[0], valid_set[i]) == 0)
			ret = settings_fct[i](params, set);
	if (i > NB_SETTINGS)
		return (print_err_msg(ERR_CODE_NOT_VALID));
	return (ret);
}

int	check_resolution(char **params, t_settings *set)
{
	int x;
	int y;

	if (set->res.x || set->res.y)
		return (print_err_msg(ERR_RES_ALREADY_ADDED));	
	else if (params[3] != NULL || !params[1] || !params[2])
		return (print_err_msg(ERR_RES_INPUTS));	
	else if (!(x = ft_atoi_exit(params[1])) || !(y = ft_atoi_exit(params[2])))
		return (print_err_msg(ERR_RES_INT_FORMAT));		
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

	if (params[2] != NULL || !params[1])
		return (print_err_msg(ERR_TEX_INPUTS));
	if (!(ft_strnstr(params[1], "./", 2)) || ft_strlen(params[1] <= 2)) // detect at beginning?
		return (print_err_msg(ERR_TEX_FORMAT));
	valid_set = (char *[NB_SETTINGS - 3]) {"NO", "SO", "WE", "EA", "S", NULL};
	textures_set = (char *[NB_SETTINGS - 3]) {set->no_texture, set->so_texture, set->we_texture, set->ea_texture, set->s_texture};
	i = -1;
	while(valid_set[++i])
	{
		// how to check the texture format? open params[1]?
		if (ft_strcmp(params[0], valid_set[i]) == 0 && !textures_set[i])
			textures_set[i] = params[1];
		else
			return (print_err_msg(ERR_TEX_ALREADY_ADDED));		
	}
	return (1);
}


int	check_colors(char **params, t_settings *set)
{
	char 	**colors;

	if (params[2] != NULL || !params[1])
		return (print_err_msg(ERR_COLOR_INPUTS));
	if (!(colors = ft_split(params[1], ",")))
		return (print_err_msg(ERR_MALLOC));	
}
