/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:31:51 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/18 17:40:58 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_mutex_forks(t_data *data)
{
	unsigned long	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			printf("philo: init_mutex_forks : i = %ld)\n", i);
			destroy_mutex_forks(data, i + 1);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_mutex_eating(t_data *data)
{
	unsigned long	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (pthread_mutex_init(&data->philo[i].eating, NULL) != 0)
		{
			printf("philo: init_mutex_eating: i = %ld\n", i);
			destroy_mutex_forks(data, data->nbr_philo);
			destroy_mutex_eating(data, i + 1);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_mutex_dead(t_data *data)
{
	if (pthread_mutex_init(&data->mutex_dead, NULL) != 0)
	{
		printf("philo: init_mutex_dead\n");
		destroy_mutex_forks(data, data->nbr_philo);
		destroy_mutex_eating(data, data->nbr_philo);
		return (false);
	}
	return (true);
}

bool	init_mutex_print(t_data *data)
{
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		printf("philo: init_mutex_print\n");
		destroy_mutex_forks(data, data->nbr_philo);
		destroy_mutex_eating(data, data->nbr_philo);
		if (pthread_mutex_destroy(&data->mutex_dead) != 0)
			printf("philo: init_mutex_print()\n");
		return (false);
	}
	return (true);
}

bool	init_mutex_time_they_eating(t_data *data)
{
	if (pthread_mutex_init(&data->m_time_they_eating, NULL) != 0)
	{
		printf("philo: init_mutex_time_they_eating\n");
		destroy_mutex_forks(data, data->nbr_philo);
		destroy_mutex_eating(data, data->nbr_philo);
		if (pthread_mutex_destroy(&data->mutex_dead) != 0)
			printf("philo: init_mutex_time_they_eating()\n");
		if (pthread_mutex_destroy(&data->print) != 0)
			printf("philo: init_mutex_time_they_eating()\n");
		return (false);
	}
	return (true);
}
