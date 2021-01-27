#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strchr(char	*s, char c)
{
	int i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_memmove(char *d, char *s, int len)
{
	if (!d && !s)
		return (NULL);
	if (s < d)
		while (len-- > 0)
			d[len] = s[len];
	else
		while (len-- > 0)
			*d++ = *s++;
	return (d);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int	l1;
	int	l2;
	int i;
	int j;

	i = 0;
	if (!s2)
		return	(NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(tab = malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	ft_memmove(tab, s1, l1);
	ft_memmove(tab + l1, s2, l2);
	tab[l1 + l2] = '\0';
	free(s1);
	return (tab);
}

char	*new_line(char *str)
{
	char *temp;
	int	i;

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
	char *temp;
	int i;
	int j;

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

int	get_next_line(int fd, char **line)
{
	int	ret;
	char	*buf;
	static char	*str;
	char *temp;

	if (*line)
	{
		temp = *line;
		free(temp);
	}
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	ret = 1;
	while (!ft_strchr(str, '\n') && (ret != 0))
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	*line = new_line(str);
	str = trunc_str(str);
	if (ret == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int fd;
	char *tab;
	int i;

	fd = 0;
	if (argv[1] && (fd = open(argv[1], O_RDONLY)) == -1)
		return (1);
	i = 1;
	while (i == 1)
	{
		printf("(result fd1:%i) - %s \n", (i = get_next_line(fd, &tab)), tab);
	}
	free(tab);
	if (close(fd) == -1)
		return (1);
	return (0);
}
