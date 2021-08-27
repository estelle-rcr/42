/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:56:50 by erecuero          #+#    #+#             */
/*   Updated: 2021/08/27 15:31:06 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	int	infile;
	int	outfile;

	if (ac < 5)
		exit_error(ERR_ARGS, av[ac - 1]);
	infile = open(av[1], O_RDONLY);
	if (infile <= 0)
		exit_error(ERR_INFILE, av[1]);
	outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (outfile <= 0)
		exit_error(ERR_OUTFILE, av[ac - 1]);
	ft_pipex(infile, outfile, ac, av, envp);
	return (EXIT_SUCCESS);
}
