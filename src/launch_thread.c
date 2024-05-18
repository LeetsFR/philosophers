/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:31:43 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/18 17:41:51 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_in_case_failure(t_data *data, unsigned long index)
{
	unsigned long	i;

	pthread_mutex_lock(&data->mutex_dead);
	data->philo_is_dead = true;
	pthread_mutex_unlock(&data->mutex_dead);
	printf("philo: launch_thread: i = %ld\n", index);
	i = 0;
	while (i < index + 1)
	{
		if (pthread_join(data->philo[i].th, NULL) != 0)
			break ;
		i++;
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_mutex_destroy(&data->philo[i].eating);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_dead);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->m_time_they_eating);
}

bool	launch_thread(t_data *data)
{
	unsigned long	i;

	data->time_start = get_time();
	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_create(&data->philo[i].th, NULL, routine,
				(void *)&data->philo[i]) != 0)
		{
			exit_in_case_failure(data, i);
			return (false);
		}
		i++;
	}
	return (true);
}
