/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:07:35 by erecuero          #+#    #+#             */
/*   Updated: 2021/10/04 18:45:50 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include "errors.h"

# define END -1
# define DEAD 0
# define EATING 1
# define THINKING 2
# define SLEEPING 3
# define FORK 4

typedef struct s_philosopher
{
	int				id;
	long			start_time;
	long			last_meal_time;
	int				state;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_must_eat;
	int				*death;
	int				ret;
	int				alive;
	int				*all_eaten;
	pthread_mutex_t	*forks[2];
	pthread_mutex_t	*print;
	pthread_mutex_t	*end;
	pthread_t		*thread;
	pthread_t		*supervisor;
}					t_philosopher;

typedef struct s_mutex_data
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	end;
	t_philosopher	*philo;
	int				all_eaten;
	int				death;
	int				nb_philo;
	long			start_time;
}					t_mutex_data;

int				main(int ac, char **av);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
int				ft_isdigit(int c);
int				ft_is_pos_num(char *number);
int				parse_args(char **av);
t_mutex_data	*create_data_struct(int ac, char **av);
int				create_philo_attr(t_mutex_data *data, int ac, char **av);
void			add_attributes_to_philo(t_mutex_data *data, int i, int ac,
					char **av);
int				init_mutex(t_mutex_data *data);
void			destroy_mutex(t_mutex_data *data);
int				threads_loop(t_mutex_data *data);
int				ft_philo(t_mutex_data *data);
void			ft_usleep(int time);
long			ft_get_time(long time);
void			free_struct(t_mutex_data *data);
int				exit_error(int error_code, t_mutex_data *data);
void			update_death(t_philosopher *philo);
void			*ft_supervise(void *arg);
void			*jobs(void *arg);
void			ft_eat(t_philosopher *philo);
void			ft_sleep_think(t_philosopher *philo);
void			ft_print(int action, t_philosopher *philo);

#endif
