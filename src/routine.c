/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:25:40 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/15 16:20:26 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_data *data, t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&data->forks[philo->philo_forks[LEFT]]);
		print_statuts("has taken a fork", philo->index, data);
		pthread_mutex_lock(&data->forks[philo->philo_forks[RIGHT]]);
		print_statuts("has taken a fork", philo->index, data);
	}
	else
	{
		pthread_mutex_lock(&data->forks[philo->philo_forks[RIGHT]]);
		print_statuts("has taken a fork", philo->index, data);
		pthread_mutex_lock(&data->forks[philo->philo_forks[LEFT]]);
		print_statuts("has taken a fork", philo->index, data);
	}
}

void	philo_eating(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	print_statuts("is eating", philo->index, data);
	philo->is_eating = true;
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->eating);
	time_to(data->time_to_eat);
	pthread_mutex_lock(&philo->eating);
	philo->is_eating = false;
	pthread_mutex_unlock(&philo->eating);
}

void	drop_forks(t_data *data, t_philo *philo)
{
		pthread_mutex_unlock(&data->forks[philo->philo_forks[LEFT]]);
		pthread_mutex_unlock(&data->forks[philo->philo_forks[RIGHT]]);
}

void	philo_sleeping(t_data *data, t_philo *philo)
{
	print_statuts("is sleeping", philo->index, data);
	time_to(data->time_to_sleep);
	print_statuts("is thinking", philo->index, data);
	if(data->nbr_philo % 2 == 1)
		usleep(data->time_to_eat * 1000);
	else
		usleep(10);
}

void	*routine(void *arg)
{
	t_philo			*philo;
	t_data			*data;
	unsigned long	i;

	philo = (t_philo *)arg;
	data = philo->data;
	i = 0;
	if(philo->index % 2 == 1)
		usleep((data->time_to_eat * 0.9) * 1000);
	while (is_dead(data) == false && i < data->time_they_eat)
	{
		take_forks(data, philo);
		philo_eating(data, philo);
		drop_forks(data, philo);
		if (i + 1 == data->time_they_eat)
		{
			pthread_mutex_lock(&data->m_time_they_eating);
			data->finished_eating++;
			pthread_mutex_unlock(&data->m_time_they_eating);
		}
		philo_sleeping(data, philo);
		i++;
	}
	return (NULL);
}
