#include <unistd.h>


/*int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}*/

int	char_seen(char c, char *s1, int i)
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

int	in_both(char c, char *s2)
{
	int j;

	j = 0;
	while (s2[j])
	{
		if (s2[j] == c)
			return (1);
		j++;
	}
	return (0);
}


void	ft_inter(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (!char_seen(s1[i], s1, i) && in_both(s1[i], s2))
			write(1, &s1[i], 1);
		i++;
	}		
	write(1, "\n", 1);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	ft_inter(av[1], av[2]);
	return (0);
}
