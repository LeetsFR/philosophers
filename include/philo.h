/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:57:38 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/18 18:02:01 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "libft.h"
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define LEFT 0
# define RIGHT 1
# define NBR_MAX_PHILO 200

typedef struct s_philo
{
	pthread_t		th;
	int				philo_forks[2];
	int				index;
	bool			is_eating;
	pthread_mutex_t	eating;
	unsigned long	last_meal;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	t_philo			philo[NBR_MAX_PHILO];
	unsigned long	nbr_philo;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_they_eat;
	unsigned long	time_start;
	unsigned long	finished_eating;
	pthread_mutex_t	forks[NBR_MAX_PHILO];
	pthread_mutex_t	print;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	m_time_they_eating;
	bool			philo_is_dead;

}					t_data;

// utils.c
bool				he_didnt_eat_on_time(t_data *data, t_philo *philo);
void				time_to(t_data *data, unsigned long time_to_wait);
bool				is_dead(t_data *data);
void				print_statuts(char *str, unsigned long index, t_data *data);
unsigned long		get_time(void);

// routine.c
void				*routine(void *arg);

// init_data.c
bool				init_data(t_data *data, char **args);

// init_philo.c
bool				init_philo(t_data *data);
bool				solo_philo(t_data *data);

// init_mutex.c
bool				init_mutex(t_data *data);
void				destroy_all_mutex(t_data *data);
void				destroy_mutex_forks(t_data *data, unsigned long size);
void				destroy_mutex_eating(t_data *data, unsigned long size);

// init_mutex_utils.c
bool				init_mutex_forks(t_data *data);
bool				init_mutex_eating(t_data *data);
bool				init_mutex_dead(t_data *data);
bool				init_mutex_print(t_data *data);
bool				init_mutex_time_they_eating(t_data *data);

// launch_thread.c
bool				launch_thread(t_data *data);

#endif
