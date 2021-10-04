/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:29:10 by erecuero          #+#    #+#             */
/*   Updated: 2021/10/04 17:31:02 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(int action, t_philosopher *philo)
{
	if (*philo->death == 0)
	{
		pthread_mutex_lock(philo->print);
		if (action == FORK && *philo->death == 0)
			printf("%ld %i has taken a fork\n", ft_get_time(philo->start_time),
				philo->id);
		else if (action == EATING && *philo->death == 0)
			printf("%ld %i is eating\n", ft_get_time(philo->start_time),
				philo->id);
		else if (action == SLEEPING && *philo->death == 0)
			printf("%ld %i is sleeping\n", ft_get_time(philo->start_time),
				philo->id);
		else if (action == THINKING && *philo->death == 0)
			printf("%ld %i is thinking\n", ft_get_time(philo->start_time),
				philo->id);
		else if (action == DEAD)
			printf("%ld %i died\n", ft_get_time(philo->start_time),
				philo->id);
		pthread_mutex_unlock(philo->print);
	}
}
