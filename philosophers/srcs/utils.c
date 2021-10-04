/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:07:58 by erecuero          #+#    #+#             */
/*   Updated: 2021/10/04 17:28:28 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time)
{
	long	now;
	long	tmp;

	now = ft_get_time(0);
	tmp = now + time;
	while (ft_get_time(0) < tmp)
		usleep(time);
	return ;
}

long	ft_get_time(long time)
{
	struct timeval	current_time;
	long			new_time;

	gettimeofday(&current_time, NULL);
	new_time = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000)
		- time;
	return (new_time);
}

void	free_struct(t_mutex_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		free((data->philo + i)->thread);
		free((data->philo + i)->supervisor);
		i++;
	}
	free(data->forks);
	free(data->philo);
	free(data);
}

int	exit_error(int error_code, t_mutex_data *data)
{
	if (error_code == ERR_NB_ARGS)
		printf("Wrong number of arguments.\n");
	if (error_code == ERR_ARGS_LIMIT)
		printf("Arguments must not be higher or lower than an integer.\n");
	if (error_code == ERR_WRG_ARGS)
		printf("Arguments must be positive integers only.\n");
	if (error_code == ERR_MUTEX_FAIL)
		printf("Mutex init failed.\n");
	if (error_code == ERR_THREAD_FAIL)
		printf("Thread creation failed.\n");
	if (data)
		free_struct(data);
	return (EXIT_FAILURE);
}
