/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:09:05 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/10 20:30:38 by erecuero         ###   ########.fr       */
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
		return (-1);
	ret = get_next_line(set.fd, &line);
	while ((ret = get_next_line(set.fd, &line)) >= 0)
	{
		params = ft_split(line, " ");
		if (check_params(params, set) == -1)
		{
			free_tab(params, count_elements(params));
			free(line);
			return (-1);
		}
		free_tab(params, count_elements(params));
		free(line);
			if (ret == 1)
		line = 0;
	}
	return (1);
}

int	check_params(char **params, t_settings set)
{
	int	c;



	if ()
	{
		print_err_msg(ERR_CODE_NOT_VALID);
		return (0);
	}



}


int	check_resolution(char **params, t_settings set)
{
	if (ft_memcmp(params[0], "R", 1) && !params[3])
	{
		if (params[1] <= 0 || params[2] <= 0)
			{
				print_err_msg(ERR_RES_TOO_HIGH);
				return (0);
			}
		// should I handle resol way too high? larger than int?
		set.res_x = params[1];
		set.res_y = params[2];
		return (1);
	}
	else
	{
		print_err_msg(ERR_RES_FORMAT);
		return (0);
	}
}

int	check_textures(char **params, t_settings set)
{
	if (params[2] != NULL)
		return (-1);
	if (!(ft_strstr(params[1], "./"))
		return (-1);

}




void	print_err_msg(int error)
{
	ft_putstr("Error:\n");

}
