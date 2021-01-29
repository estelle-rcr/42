#include <unistd.h>

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_seen(char c, char *s1, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (s1[j] == c)
			return (1);
		j++;
	}
	return (0);
}

int ft_strchr(char c, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_union(char *s1, char *s2)
{
	int l1;
	int l2;
	int i;
	int j;

	i = 0;
	j = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	char str[l1 + l2 + 1];
	str[0] = '\0';
	while (s1[i])
	{
		if (!is_seen(s1[i], s1, i) && !ft_strchr(s1[i], str))
		{
			str[j] = s1[i];
			str[++j] = '\0';
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (!is_seen(s2[i], s2, i) && !ft_strchr(s2[i], str))
		{	
			str[j] = s2[i];
			str[++j] = '\0';
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main (int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	ft_union(av[1], av[2]);
	return (0);
}
