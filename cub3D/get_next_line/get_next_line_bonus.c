/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:38:41 by erecuero          #+#    #+#             */
/*   Updated: 2020/12/01 15:38:49 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*new_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	line[i] = '\0';
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	return (line);
}

char	*trunc_str(char *str)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	if (!(temp = malloc(sizeof(char) * (ft_strlen(str) - i + 1))))
		return (NULL);
	j = 0;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	free(str);
	return (temp);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		*buf;
	static char	*str[MAX_FD];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	ret = 1;
	while (!ft_strchr(str[fd], '\n') && (ret != 0))
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
	}
	free(buf);
	*line = new_line(str[fd]);
	str[fd] = trunc_str(str[fd]);
	if (ret == 0)
		return (0);
	return (1);
}
