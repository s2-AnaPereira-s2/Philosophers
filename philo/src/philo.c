/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:50:05 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/10/29 16:57:26 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_philos_ate(t_p *data)
{
	int	i;
	int	all_ate;

	if (data->total_meals <= 0)
		return (0); 
	i = 0;
	all_ate = 1;
	while (i < data->total_philos)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->philos[i].meals_eaten < data->total_meals)
			all_ate = 0;
		pthread_mutex_unlock(&data->death_mutex);
		if (!all_ate)
			return (0);
		i++;
	}
	return (1);
}

int	check_philo_death(t_p *data, int i)
{
	long	current_time;
	long	time_since_last_meal;

	current_time = get_time();
	pthread_mutex_lock(&data->death_mutex);
	time_since_last_meal = current_time - data->philos[i].last_meal_time;
	pthread_mutex_unlock(&data->death_mutex);
	if (time_since_last_meal >= data->tt_die)
	{
		pthread_mutex_lock(&data->death_mutex);
		data->dead = 1;
		pthread_mutex_unlock(&data->death_mutex);
		pthread_mutex_lock(&data->print_mutex);
		printf("%ld %d died\n", current_time - data->start_time, 
			data->philos[i].id);
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	return (0);
}

void	philos_check(t_p *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->total_philos)
		{
			if (check_philo_death(data, i))
				return ;
			i++;
		}
		if (all_philos_ate(data))
		{
			pthread_mutex_lock(&data->death_mutex);
			data->dead = 1;
			printf("%s", "All philosophers have eaten the required meals\n");
			pthread_mutex_unlock(&data->death_mutex);
			return ;
		}
		usleep(1000);
	}
}
