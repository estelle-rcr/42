/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:28:21 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/25 18:41:18 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_err_msg(int error)
{
	// main error
	if (error == 0)
		ft_putstr("Error\nThe number of arguments is not valid. Recommended use: ./cub3D map.cub or ./cub3D map.cub --save\n");

	// open_file error
	else if (error == 1)
		perror("Error\nWrong type of file. The file extension must be .cub\n");
	else if (error == 2)
		ft_putstr("Error\nCan't use a directory as a setup file.\n");
	else if (error == 3)
	{
		ft_putstr(strerror(errno));
		perror("Error\nCouldn't open the file correctly.\n");
	}

	// ft_parse_file
	else if (error == 4)
		ft_putstr("Error\nThe malloc function went wrong.\n");
	else if (error == 5)
		ft_putstr("Error\nThere is a parameter missing in the .cub file.\n");
	else if (error == 6)
		ft_putstr("Error\nGet_next_line function encountered an error.\n");

	// ft check params
	else if (error == 7)
		ft_putstr("Error\nOne parameter's code is not valid.\n");

	// ft check resolution
	else if (error == 8)
		ft_putstr("Error\nThe resolution can't be less than 1 * 1 pixel.\n");
    else if (error == 9)
		ft_putstr("Error\nToo many resolution parameters were provided.\n");
	else if (error == 10)
		ft_putstr("Error\nThe resolution must be 2 positive numbers.\n");
	else if (error == 11)
		ft_putstr("Error\nWrong arguments in the resolution parameter.\n");

	//ft check textures
    else if (error == 12)
        ft_putstr("Error\nWrong arguments in the texture parameter.\n");
    else if (error == 13)
        ft_putstr("Error\nThe texture parameter's argument is not valid.\n");
    else if (error == 14)
		ft_putstr("Error\nEach texture parameter must be given only once.\n");

	// ft check colors
    else if (error == 15)
		ft_putstr("Error\nWrong arguments in the color parameters.\n");
    else if (error == 16)
		ft_putstr("Error\nColors should be 3 numbers between 0 and 255.\n");
    else if (error == 17)
		ft_putstr("Error\nEach color parameter must be given only once.\n");

	// ft check map
	else if (error == 18)
		ft_putstr("Error\nOne line isn't valid regarding the map format.\n");
	else if (error == 19)
		ft_putstr("Error\nThe map is not playable (wrong element).\n");
	else if (error == 20)
		ft_putstr("Error\nThe player position must be given only once.\n");

	return (0);
}

