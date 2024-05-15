/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcollas <mcollas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:25:30 by mcollas           #+#    #+#             */
/*   Updated: 2024/05/14 17:25:31 by mcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_int_arg(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			printf("Error: need a numeric arg\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	check_args(char **args)
{
	size_t	i;
	long	tmp;

	i = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) >= 11)
		{
			printf("Error: need int value\n");
			return (false);
		}
		if (is_int_arg(args[i]) == false)
		{
			printf("Error: need int value\n");
			return (false);
		}
		tmp = ft_atol(args[i]);
		if (tmp <= 0 || tmp > INT_MAX)
		{
			printf("Error: need a positive int value\n");
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_data(t_data *data, char **args)
{
	if (check_args(args) == false)
		return (false);
	data->nbr_philo = ft_atoul(args[0]);
	if (data->nbr_philo > NBR_MAX_PHILO)
	{
		printf("Error: MAX PHILO = %d\n", NBR_MAX_PHILO);
		return (false);
	}
	data->time_to_die = ft_atoul(args[1]);
	data->time_to_eat = ft_atoul(args[2]);
	data->time_to_sleep = ft_atoul(args[3]);
	if (args[4])
		data->time_they_eat = ft_atoul(args[4]);
	else
		data->time_they_eat = LONG_MAX;
	data->philo_is_dead = false;
	data->finished_eating = 0;
	return (true);
}
