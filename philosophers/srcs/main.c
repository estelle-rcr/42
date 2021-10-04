/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:07:50 by erecuero          #+#    #+#             */
/*   Updated: 2021/10/01 17:12:42 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_mutex_data	*data;

	if (ac < 5 || ac > 6)
	{
		exit_error(ERR_NB_ARGS, NULL);
		return (EXIT_FAILURE);
	}
	else
	{
		if (parse_args(av))
		{
			data = create_data_struct(ac, av);
			if (!data)
				return (EXIT_FAILURE);
			if (!ft_philo(data))
				return (EXIT_FAILURE);
			free_struct(data);
		}
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
