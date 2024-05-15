/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:25:38 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/14 17:41:46 by mcollas          ###   ########.fr       */
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
			pthread_mutex_lock(&data->philo[i].eating);
			if ((get_time() - data->philo[i].last_meal) >= data->time_to_die
				&& (data->philo[i].is_eating == false))
			{
				print_statuts("died", data->philo[i].index, data);
				pthread_mutex_lock(&data->mutex_dead);
				data->philo_is_dead = true;
				pthread_mutex_unlock(&data->philo[i].eating);
				pthread_mutex_unlock(&data->mutex_dead);
				return ;
			}
			pthread_mutex_unlock(&data->philo[i].eating);
			i++;
		}
		usleep(100);
	}
}

void	exit_philo(t_data *data, t_philo *philo)
{
	unsigned long	i;

	i = 0;
	while (i < philo->data->nbr_philo)
	{
			pthread_join(philo[i].th, NULL);
			pthread_mutex_destroy(&philo[i].eating);
			pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_dead);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->m_time_they_eating);
}

bool solo_philo(t_data *data)
{
	if(data->nbr_philo == 1)	
	{
		printf("0 1 has taken a fork\n");
		time_to(data->time_to_die);
		printf("%ld 1 died\n",data->time_to_die);
		return(true);
	}
	return(false);
}

int	philo(char **args)
{
	unsigned long	i;
	t_data			data;

	if (init_data(&data, args) == false)
		return (1);
	if(solo_philo(&data)== true)
		return(888);
	if (init_philo(&data) == false)
		return (2);
	data.time_start = get_time();
	i = 0;
	while (i < data.nbr_philo)
	{
		pthread_create(&data.philo[i].th, NULL, routine,
			(void *)&data.philo[i]);
		i++;
		usleep(100);
	}
	someone_is_dead(&data);
	exit_philo(&data, data.philo);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc >= 5 && argc <= 6)
		return (philo(argv + 1));
	printf("Error: 5 or 6 args.\n ");
	return (-1);
}
