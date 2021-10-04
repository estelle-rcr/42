/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:56:21 by erecuero          #+#    #+#             */
/*   Updated: 2021/10/04 17:42:05 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_death(t_philosopher *philo)
{
	philo->alive = DEAD;
	ft_print(DEAD, philo);
	*philo->death = 1;
	pthread_mutex_unlock(philo->end);
}

void	*ft_supervise(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (*philo->death == 0)
	{
		pthread_mutex_lock(philo->end);
		if ((ft_get_time(0) - philo->last_meal_time) > philo->time_die)
		{
			update_death(philo);
			break ;
		}
		if (*(philo->all_eaten) == 0)
		{
			philo->alive = END;
			pthread_mutex_unlock(philo->end);
			break ;
		}
		else if (philo->time_must_eat == 0)
		{
			*(philo->all_eaten) -= 1;
			philo->time_must_eat = -1;
		}
		pthread_mutex_unlock(philo->end);
	}
	return (0);
}

void	*jobs(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	philo->ret = pthread_create(philo->supervisor, NULL, ft_supervise, philo)
		!= 0;
	if (philo->ret)
		return (&philo->ret);
	while (*philo->death == 0 && *philo->all_eaten)
	{
		if (philo->state == THINKING)
			ft_eat(philo);
		else
			ft_sleep_think(philo);
		if (!(philo->forks[philo->id % 2]))
			break ;
	}
	pthread_join(*philo->supervisor, NULL);
	return (0);
}

void	ft_eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->forks[!(philo->id % 2)]);
	ft_print(FORK, philo);
	if (!(philo->forks[philo->id % 2]))
	{
		pthread_mutex_unlock(philo->forks[!(philo->id % 2)]);
		return ;
	}
	pthread_mutex_lock(philo->forks[philo->id % 2]);
	if (*philo->death || *philo->all_eaten == 0)
	{
		pthread_mutex_unlock(philo->forks[!(philo->id % 2)]);
		pthread_mutex_unlock(philo->forks[(philo->id % 2)]);
		return ;
	}
	ft_print(FORK, philo);
	ft_print(EATING, philo);
	philo->state = EATING;
	philo->last_meal_time = ft_get_time(0);
	if (philo->time_must_eat > 0)
		philo->time_must_eat--;
	ft_usleep(philo->time_eat);
	pthread_mutex_unlock(philo->forks[philo->id % 2]);
	pthread_mutex_unlock(philo->forks[!(philo->id % 2)]);
}

void	ft_sleep_think(t_philosopher *philo)
{
	if (philo->state == EATING)
	{
		ft_print(SLEEPING, philo);
		philo->state = SLEEPING;
		ft_usleep(philo->time_sleep);
	}
	else if (philo->state == SLEEPING)
	{
		usleep(100);
		ft_print(THINKING, philo);
		philo->state = THINKING;
	}
}
