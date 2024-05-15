/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:25:35 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/15 16:22:23 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	solo_philo(t_data *data)
{
	if (data->nbr_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		time_to(data->time_to_die);
		printf("%ld 1 died\n", data->time_to_die);
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
		pthread_mutex_init(&data->forks[i], NULL);
		pthread_mutex_init(&data->philo[i].eating, NULL);
		data->philo[i].data = data;
		data->philo[i].philo_forks[LEFT] = i;
		data->philo[i].philo_forks[RIGHT] = (i + 1) % data->nbr_philo;
		data->philo[i].last_meal = get_time();
		data->philo[i].index = i + 1;
		data->philo[i].is_eating = false;
		i++;
	}
	pthread_mutex_init(&data->mutex_dead, NULL);
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->m_time_they_eating, NULL);
	return (true);
}
