/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:22:54 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/17 15:56:32 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

char	*new_line(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(temp = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	temp[i] = '\0';
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		temp[i] = str[i];
		i++;
	}
	return (temp);
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
	static char	*str;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	ret = 1;
	while (!ft_strfind(str, '\n') && (ret != 0))
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		if (!(str = ft_joinstr(str, buf)))
			return (-1);
	}
	free(buf);
	*line = new_line(str);
	str = trunc_str(str);
	return (ret);
}
