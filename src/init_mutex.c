/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:31:48 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/18 17:33:22 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex_forks(t_data *data, unsigned long size)
{
	unsigned long	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_destroy(&data->forks[i]) != 0)
			printf("philo: destroy_mutex_forks: i = %ld)\n",
				i);
		i++;
	}
}

void	destroy_mutex_eating(t_data *data, unsigned long size)
{
	unsigned long	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_destroy(&data->philo[i].eating) != 0)
			printf("philo: destroy_mutex_eating: i = %ld\n",
				i);
		i++;
	}
}

bool	init_mutex(t_data *data)
{
	if (init_mutex_forks(data) == false)
		return (false);
	if (init_mutex_eating(data) == false)
		return (false);
	if (init_mutex_dead(data) == false)
		return (false);
	if (init_mutex_print(data) == false)
		return (false);
	if (init_mutex_time_they_eating(data) == false)
		return (false);
	return (true);
}
