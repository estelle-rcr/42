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
	t_settings set;
	int ret;

	set.fd = open_file(file);
	if (set.fd == -1)
	{
		print_err_msg(ERR_OPEN_FILE);
		return (-1);
	}
	while ((ret = get_next_line(set.fd, &line)) >= 0)
	{
		params = ft_split(line, " ");
		if (check_params(params, &set) == -1)
		{
			free_tab(params, count_elements(params));
			free(line);
			print_err_msg(ERR_MALLOC);
			return (-1);
		}
		free_tab(params, count_elements(params));
		free(line);
		if (ret == 1)
			line = 0;
	}
	is_missing_params(set);
	return (1);
}

int	check_params(char **params, t_settings *set)
{
	int		(*settings_fct[NB_SETTINGS])(char**, t_settings*);
	char	*valid_set[NB_SETTINGS];
	int i;
	int ret;

	i = 0;
	valid_set = {"R", "NO", "SO", "WE", "EA", "S", "F", "C"};
	settings_fct[0] = &check_resolution;
	while (++i <= 5)
		settings_fct[i] = &check_textures;
	settings_fct[6] = &check_colors;
	settings_fct[7] = &check_colors;
	i = -1;
	ret = -1;
	while(valid_set[++i])
		if (ft_strcmp(params[0], valid_set[i])== 0)
			ret = settings_fct[i](params, set);
	if (!ret)
	{
		print_err_msg(ERR_CODE_NOT_VALID);
		return (-1);
	}
	return (ret);
}

int	check_resolution(char **params, t_settings *set)
{
	if (params[1] <= 0 || params[2] <= 0)
	{
		print_err_msg(ERR_NEGATIVE_RES);
		return (-1);
	}
	else if (!params[3] && is_num(params[1]) && is_num(params[2]))
	{
		// should I handle resol way too high? larger than int?
		set->res.x = params[1];
		set->res.y = params[2];
		return (1);
	}
	else
	{
		print_err_msg(ERR_RES_FORMAT);
		return (-1);
	}
}

int	check_textures(char **params, t_settings *set)
{
	if (params[2] != NULL)
		return (-1);
	if (!(ft_strstr(params[1], "./"))
		return (-1);

}




void	print_err_msg(int error)
{

	ft_putstr("Error\nCouldn't open the file correctly.\n");
}
