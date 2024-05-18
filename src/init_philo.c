/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:25:35 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/18 17:31:04 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	*solo_routine(void *arg)
{
	t_data			*data;
	unsigned long	time;

	time = get_time();
	data = (t_data *)arg;
	printf("0 1 has taken a fork\n");
	while (get_time() - time < data->time_to_die)
		usleep(100);
	printf("%ld 1 died\n", data->time_to_die);
	return (NULL);
}

bool	solo_philo(t_data *data)
{
	pthread_t	th;

	if (data->nbr_philo == 1)
	{
		if (pthread_create(&th, NULL, solo_routine, (void *)data) != 0)
		{
			printf("philo: pthread_create()\n");
			return (true);
		}
		pthread_join(th, NULL);
		return (true);
	}
	return (false);
}

bool	init_philo(t_data *data)
{
	unsigned long	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		data->philo[i].data = data;
		data->philo[i].philo_forks[LEFT] = i;
		data->philo[i].philo_forks[RIGHT] = (i + 1) % data->nbr_philo;
		data->philo[i].last_meal = get_time();
		data->philo[i].index = i + 1;
		data->philo[i].is_eating = false;
		i++;
	}
	return (true);
}
