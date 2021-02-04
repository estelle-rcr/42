/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:27:24 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/04 16:24:49 by erecuero         ###   ########.fr       */
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
	int fd;

	if (!check_format(file, ".cub"))
	{
		ft_putstr(strerror(errno));
		perror("Error\nWrong type of file. The file extension must be .cub\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(strerror(errno));
		perror("Error\nCouldn't open the file correctly.\n");
		return (-1);
	}
	return (fd);
}

int	main(int ac, char **av)
{

/*	if (ac == 3)
		option '--save'
*/
	if (ac == 2 || ac == 3)
	{
		parse_file(fd, av[1]);
		return (0);
	}
	else
	{
		ft_putstr(strerror(errno));
		perror("Error\nThe number of arguments is not valid. Recommended use: ./play
				map.cub or ./play map.cub --save\n");
		return (1);
	}
}
