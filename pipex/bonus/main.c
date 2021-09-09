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
	if (ac < 5)
		exit_error(ERR_ARGS, av[ac - 1]);
	ft_pipex(ac, av, envp);
	return (EXIT_SUCCESS);
}
