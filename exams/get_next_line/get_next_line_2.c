#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#ifndef FD
# define FD 0
#endif


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

int	get_next_line(char **line)
{
	int	ret;
	char buf[BUFFER_SIZE];
	static char *str;

	if (FD < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = 1;
	while (!ft_str_search('\n', str) && (ret != 0))
	{
		if ((ret = read(FD, buf, BUFFER_SIZE)) == -1)
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

int main()
{
    int ret;
    char *line;

    line = 0;
    ret = get_next_line(&line);
    while (ret > 0)
    {
        write(1, line, ft_strlen(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
        ret = get_next_line(&line);
    }
    if (ret == 0)
    {
        write(1, line, ft_strlen(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
    }
}
