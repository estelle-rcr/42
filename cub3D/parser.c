/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:09:05 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/04 17:22:51 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_settings	*new_set(void)
{
	//malloc struct
}

int	parse_file(char *file)
{
	char *line;
	char **params;
	t_settings *set;
	int ret;

	set = new_set();
	set->fd = open_file(file);
	if (set->fd == -1)
		return (-1);
	ret = get_next_line(set->fd, &line);
	while (ret > 0)
	{
		params = ft_split_sep(line, " ,");
		if (check_params(params) == -1)
			// error, free, sortir
		free_tab(params, count_elements(params));
		free(line);
		line = 0;
		ret = get_next_line(fd, &line);
	}
	if (ret == 0)
	{
		// map toujours terminee par \n ? ligne avec EOF a recuperer ?
		...
		free(line);
	}
}


