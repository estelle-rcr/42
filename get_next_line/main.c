#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int fd;
	int fd2;
	int fd3;
	int fd4;
	int i;
	int j;
	char *tab[1];

	if (argc > 5)
		return (1);
	fd = -1;
	fd2 = 0;
	fd3 = 0;
	fd4 = 0;
/*	(void)argv;*/
	if (argv[1] && (fd = open(argv[1], O_RDONLY)) == -1)
		return (1);
	if (argv[2] && (fd2 = open(argv[2], O_RDONLY)) == -1)
		return (1);
/*	if (argv[3] && (fd3 = open(argv[3], O_RDONLY)) == -1)
		return (1);
	if (argv[4] && (fd4 = open(argv[4], O_RDONLY)) == -1)
		return (1); */
	i = 1;
	while (i == 1)
	{
		printf("(result fd1:%i) - %s \n", (i = get_next_line(fd, tab)), *tab);
	}
	i = 1;
	while (i == 1)
	{
		printf("(result fd2:%i) - %s \n", (i = get_next_line(fd2, tab)), *tab);
	}
	i = 1;
	j = 1;
/*	while (fd3 && fd4 && i == 1 && j == 1)
	{
		printf("(result fd3:%i) - %s \n", (i = get_next_line(fd3, tab)), *tab);
		printf("(result fd4:%i) - %s \n", (j = get_next_line(fd4, tab)), *tab);
	}*/
	if (close(fd) == -1)
		return (1);
	if (close(fd2) == -1)
		return (1);
/*	if (close(fd3) == -1)
		return (1);
	if (close(fd4) == -1)
		return (1);*/
	return (0);
}
