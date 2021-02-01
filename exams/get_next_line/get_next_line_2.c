#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	return(i);
}

int	ft_str_search(char c, char *s)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char *tab;
	int i;
	int j;
	int l1;
	int l2;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(tab = malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		tab[i++] = s2[j++];
	}
	tab[i] = '\0';
	free(s1);
	return (tab);
}

char	*new_line(char *str)
{
	int i;
	char *temp;

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

char *trunc_str(char *str)
{
	char *temp;
	int i;
	int j;

	if (!str)
		return (NULL);
	i = 0;
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
	char buf[BUFFER_SIZE];
	static char *str;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = 1;
	while (!ft_str_search('\n', str) && (ret != 0))
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
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
	(void) argc;
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
