/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:25:38 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/17 23:10:25 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

bool	he_finished_to_eat(t_data *data)
{
	pthread_mutex_lock(&data->m_time_they_eating);
	if (data->finished_eating == data->nbr_philo)
	{
		pthread_mutex_unlock(&data->m_time_they_eating);
		return (true);
	}
	pthread_mutex_unlock(&data->m_time_they_eating);
	return (false);
}

void	someone_is_dead(t_data *data)
{
	unsigned long	i;

	while (true)
	{
		i = 0;
		while (i < data->nbr_philo)
		{
			if (he_finished_to_eat(data) == true)
				return ;
			if (he_didnt_eat_on_time(data, &data->philo[i]) == true)
			{
				pthread_mutex_lock(&data->print);
				pthread_mutex_lock(&data->mutex_dead);
				data->philo_is_dead = true;
				printf("%ld %d died\n", get_time() - data->time_start,
					data->philo[i].index);
				pthread_mutex_unlock(&data->print);
				pthread_mutex_unlock(&data->mutex_dead);
				return ;
			}
			usleep(10);
			i++;
		}
	}
}

void	exit_philo(t_data *data)
{
	unsigned long	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_join(data->philo[i].th, NULL);
		pthread_mutex_lock(&data->philo[i].eating);
		pthread_mutex_unlock(&data->philo[i].eating);
		pthread_mutex_destroy(&data->philo[i].eating);
		pthread_mutex_lock(&data->forks[i]);
		pthread_mutex_unlock(&data->forks[i]);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_lock(&data->mutex_dead);
	pthread_mutex_unlock(&data->mutex_dead);
	pthread_mutex_destroy(&data->mutex_dead);
	pthread_mutex_lock(&data->print);
	pthread_mutex_unlock(&data->print);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_lock(&data->m_time_they_eating);
	pthread_mutex_unlock(&data->m_time_they_eating);
	pthread_mutex_destroy(&data->m_time_they_eating);
}

int	philo(char **args)
{
	unsigned long	i;
	t_data			data;

	if (init_data(&data, args) == false)
		return (1);
	if (solo_philo(&data) == true)
		return (888);
	if (init_philo(&data) == false)
		return (2);
	data.time_start = get_time();
	i = 0;
	while (i < data.nbr_philo)
	{
		pthread_create(&data.philo[i].th, NULL, routine,
			(void *)&data.philo[i]);
		i++;
	}
	someone_is_dead(&data);
	exit_philo(&data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc >= 5 && argc <= 6)
		return (philo(argv + 1));
	printf("Error: 5 or 6 args.\n ");
	return (-1);
}
