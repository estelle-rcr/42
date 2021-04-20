/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:28:21 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/16 14:20:34 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_err_msg(int error)
{
	if ((error >= 0 && error <= 7) || error >= 27)
		return (error_files(error));
	else if (error >= 8 && error <= 17)
		return (error_rtc(error));
	else if (error >= 18 && error <= 20)
		return (error_map(error));
	else if (error >= 21 && error <= 26)
		return (error_mlx(error));

	return (0);
}

int	error_files(int error)
{
	if (error == 0)
		ft_putstr("Error\nUse ./cub3D map.cub or ./cub3D map.cub --save\n");
	else if (error == 1)
		perror("Error\nWrong type of file. The file extension must be .cub\n");
	else if (error == 2)
		ft_putstr("Error\nCan't use a directory as a setup file.\n");
	else if (error == 3)
	{
		ft_putstr(strerror(errno));
		perror("Error\nCouldn't open the file correctly.\n");
	}
	else if (error == 4)
		ft_putstr("Error\nThe malloc function went wrong.\n");
	else if (error == 5)
		ft_putstr("Error\nThere is a parameter missing in the .cub file.\n");
	else if (error == 6)
		ft_putstr("Error\nGet_next_line function encountered an error.\n");
	else if (error == 7)
		ft_putstr("Error\nOne parameter's code is not valid.\n");
	else if (error == 27)
		ft_putstr("Error\nCoudln't close the settings file (fd)\n");
	return (0);
}

int	error_rtc(int error)
{
	if (error == 8)
		ft_putstr("Error\nThe resolution can't be less than 1 * 1 pixel.\n");
	else if (error == 9)
		ft_putstr("Error\nToo many resolution parameters were provided.\n");
	else if (error == 10)
		ft_putstr("Error\nThe resolution must be 2 positive numbers.\n");
	else if (error == 11)
		ft_putstr("Error\nWrong arguments in the resolution parameter.\n");
	else if (error == 12)
		ft_putstr("Error\nWrong arguments in the texture parameter.\n");
	else if (error == 13)
		ft_putstr("Error\nThe texture parameter's argument is not valid.\n");
	else if (error == 14)
		ft_putstr("Error\nEach texture parameter must be given only once.\n");
	else if (error == 15)
		ft_putstr("Error\nWrong arguments in the color parameters.\n");
	else if (error == 16)
		ft_putstr("Error\nColors should be 3 numbers between 0 and 255.\n");
	else if (error == 17)
		ft_putstr("Error\nEach color parameter must be given only once.\n");
	return (0);
}

int	error_map(int error)
{
	if (error == 18)
		ft_putstr("Error\nOne line isn't valid regarding the map format.\n");
	else if (error == 19)
		ft_putstr("Error\nThe map is not playable (wrong element).\n");
	else if (error == 20)
		ft_putstr("Error\nThe player position must be given only once.\n");
	return (0);
}

int	error_mlx(int error)
{
	if (error == 21)
		ft_putstr("Error\nCouldn't generate mlx pointer.\n");
	else if (error == 22)
		ft_putstr("Error\nCouldn't generate mlx window.\n");
	else if (error == 23)
		ft_putstr("Error\nCouldn't generate mlx image correctly.\n");
    else if (error == 24)
		ft_putstr("Error\nCouldn't retrieve texture image.");
	else if (error == 25)
		ft_putstr("Error\nCouldn't destroy correctly MLX components.");
	else if (error == 25)
		ft_putstr("Error\nCoudln't open the BMP file (fd)\n");
	else if (error == 26)
		ft_putstr("Error\nCoudln't close the BMP file (fd)\n");
	return (0);
}
