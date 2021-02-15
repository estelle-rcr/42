/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:28:21 by erecuero          #+#    #+#             */
/*   Updated: 2021/02/11 14:28:29 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_err_msg(int error)
{
	if (error == 0)
		ft_putstr("Error\nThe number of arguments is not valid. Recommended use:
		./cub3D map.cub or ./cub3D map.cub --save\n");
	else if (error == 1)
		perror("Error\nWrong type of file. The file extension must be .cub\n");
	else if (error == 2)
	{
		ft_putstr(strerror(errno));
		perror("Error\nCouldn't open the file correctly.\n");
	}
	else if (error == 3)
		ft_putstr("Error\nThe malloc function went wrong.\n");
	else if (error == 4)
		ft_putstr("Error\nThere is one or more parameters missing in the cub file.\n");
	else if (error == 5)
		ft_putstr("Error\nOne parameter's code is not valid.\n");
	else if (error == 6)
		ft_putstr("Error\nThe resolution can't be less than 1 * 1 pixel.\n");
    else if (error == 7)
		ft_putstr("Error\nThe resolution parameter must be given only once.\n");
	else if (error == 8)
		ft_putstr("Error\nThe resolution parameters were not 2 integers.\n");
	else if (error == 9)
		ft_putstr("Error\nToo many aruments in the resolution parameter.\n");
    else if (error == 10)
        ft_putstr("Error\nToo many aruments in the texture parameter.\n");
    else if (error == 11)
        ft_putstr("Error\nThe texture parameter argument is not a valid format.\n");
    else if (error == 12)
		ft_putstr("Error\nEach texture parameter must be given only once.\n");
	return (0);
}

