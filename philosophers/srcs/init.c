/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:00:13 by erecuero          #+#    #+#             */
/*   Updated: 2021/10/04 18:40:33 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_pos_num(char *number)
{
	int	i;

	i = 0;
	while (*number)
	{
		if (!ft_isdigit(*number))
			return (0);
		number++;
	}
	return (1);
}

int	parse_args(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < -2147483648
			|| ft_atol(av[i]) == -1)
		{
			exit_error(ERR_ARGS_LIMIT, NULL);
			return (0);
		}
		if (!ft_is_pos_num(av[i]))
		{
			exit_error(ERR_WRG_ARGS, NULL);
			return (0);
		}
	}
	return (1);
}

t_mutex_data	*create_data_struct(int ac, char **av)
{
	t_mutex_data	*data;

	data = (t_mutex_data *)malloc(sizeof(t_mutex_data));
	if (!data)
	{
		exit_error(ERR_MALLOC_STRUCT, NULL);
		return (0);
	}
	data->start_time = ft_get_time(0);
	data->nb_philo = ft_atoi(av[1]);
	data->death = 0;
	data->all_eaten = data->nb_philo;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nb_philo);
	data->philo = (t_philosopher *)malloc(sizeof(t_philosopher)
			* data->nb_philo);
	if (!data->forks || !data->philo)
	{
		exit_error(ERR_MALLOC_DATA, data);
		return (0);
	}
	if (!create_philo_attr(data, ac, av))
		return (0);
	return (data);
}

int	create_philo_attr(t_mutex_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	while ((data->forks + i) && (data->philo + i) && i < data->nb_philo)
	{
		add_attributes_to_philo(data, i, ac, av);
		(data->philo + i)->thread = (pthread_t *)malloc(sizeof(pthread_t));
		(data->philo + i)->supervisor = (pthread_t *)malloc(sizeof(pthread_t));
		if (!(data->philo + i)->thread || !(data->philo + i)->supervisor)
		{
			exit_error(ERR_MALLOC_DATA, data);
			return (0);
		}
		(data->philo + i)->forks[0] = (data->forks + i);
		if (i + 1 < data->nb_philo && (data->forks + i + 1))
			(data->philo + i)->forks[1] = (data->forks + i + 1);
		else if (data->nb_philo == 1)
			(data->philo + i)->forks[1] = NULL;
		else
			(data->philo + i)->forks[1] = data->forks;
		i++;
	}
	return (1);
}

void	add_attributes_to_philo(t_mutex_data *data, int i, int ac, char **av)
{
	(data->philo + i)->start_time = data->start_time;
	(data->philo + i)->print = &data->print;
	(data->philo + i)->end = &data->end;
	(data->philo + i)->death = &data->death;
	(data->philo + i)->all_eaten = &data->all_eaten;
	(data->philo + i)->id = i + 1;
	(data->philo + i)->alive = 1;
	(data->philo + i)->state = THINKING - !((data->philo + i)->id % 2);
	(data->philo + i)->time_die = ft_atoi(av[2]);
	(data->philo + i)->time_eat = ft_atoi(av[3]);
	(data->philo + i)->time_sleep = ft_atoi(av[4]);
	(data->philo + i)->last_meal_time = data->start_time;
	if (ac == 6)
		(data->philo + i)->time_must_eat = ft_atoi(av[5]);
	else
		(data->philo + i)->time_must_eat = -1;
}
