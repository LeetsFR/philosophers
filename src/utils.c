/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:25:42 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/14 17:25:43 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	swap_deadlock(t_philo *philo)
{
	int	tmp;

	tmp = philo->philo_forks[LEFT];
	philo->philo_forks[LEFT] = philo->philo_forks[RIGHT];
	philo->philo_forks[RIGHT] = tmp;
	usleep(100);
}

void	time_to(unsigned long time_to_wait)
{
	unsigned long	time;

	time = get_time();
	while (get_time() - time < time_to_wait)
		usleep(100);
}

bool	is_dead(t_data *data)
{
	bool	tmp;

	pthread_mutex_lock(&data->mutex_dead);
	tmp = data->philo_is_dead;
	pthread_mutex_unlock(&data->mutex_dead);
	return (tmp);
}

void	print_statuts(char *str, unsigned long index, t_data *data)
{
	pthread_mutex_lock(&data->print);
	pthread_mutex_lock(&data->mutex_dead);
	usleep(10);
	if (data->philo_is_dead == true)
	{
		pthread_mutex_unlock(&data->mutex_dead);
		pthread_mutex_unlock(&data->print);
		return ;
	}
	pthread_mutex_unlock(&data->mutex_dead);
	printf("%ld %ld %s\n", get_time() - data->time_start, index, str);
	pthread_mutex_unlock(&data->print);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
