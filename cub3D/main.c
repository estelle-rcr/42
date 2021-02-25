/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:27:24 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/17 11:44:31 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{

/*	if (ac == 3 && ft_strlen(av[2]) == 6 && ft_strnstr(ac[2], '--save', 6))
		option '--save'
*/
	if (ac == 2 || ac == 3)
	{
		read_file(av[1]);
		return (0);
	}
	else
	{
		print_err_msg(ERR_NUMBER_ARGS);
		return (1);
	}
}
