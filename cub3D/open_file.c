/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:25:49 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/04 17:11:59 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_format(char *file, char *type)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = 0;
	len = ft_strlen(type);
	while (file[i])
	{
		while (file[i + j] == type[j])
		{
			j++;
			if (j == len && !file[i + j + 1])
				return (1);
		}
		j = 0;
		i++;
	}
	return (0);
}

int	open_file(char *file)
{
	int	fd;

	if (!check_format(file, ".cub"))
	{
		ft_putstr(strerror(errno));
		perror("Error\nWrong type of file. The file extension must be .cub\n");
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(strerror(errno));
		perror("Error\nCouldn't open the file correctly.\n");
		return (-1);
	}
	return (fd);
}
