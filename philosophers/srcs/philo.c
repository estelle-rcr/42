/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:07:53 by erecuero          #+#    #+#             */
/*   Updated: 2021/10/04 17:46:32 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_mutex_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		exit_error(ERR_MUTEX_FAIL, data);
		return (0);
	}
	if (pthread_mutex_init(&data->end, NULL) != 0)
	{
		exit_error(ERR_MUTEX_FAIL, data);
		return (0);
	}
	while (data->forks + i && i < data->nb_philo)
	{
		if (pthread_mutex_init(data->forks + i, NULL) != 0)
		{
			exit_error(ERR_MUTEX_FAIL, data);
			return (0);
		}
		i++;
	}
	return (1);
}

void	destroy_mutex(t_mutex_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->end);
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
}

int	threads_loop(t_mutex_data *data)
{
	int	err;
	int	i;

	i = 0;
	while (&data->philo[i] && i < data->nb_philo)
	{
		err = pthread_create(data->philo[i].thread, NULL, jobs,
				&data->philo[i]);
		if (err != 0)
		{
			exit_error(ERR_THREAD_FAIL, data);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_philo(t_mutex_data *data)
{
	int	i;

	if (!init_mutex(data))
		return (0);
	if (!threads_loop(data))
		return (0);
	i = -1;
	while (++i < data->nb_philo)
		pthread_join(*(data->philo + i)->thread, NULL);
	destroy_mutex(data);
	return (1);
}
