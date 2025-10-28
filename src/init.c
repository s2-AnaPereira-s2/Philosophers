/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:41:00 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/10/27 15:24:35 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_p *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		if (i < data->total_philos - 1)
			data->philos[i].right_fork = &data->forks[i + 1];
		else
			data->philos[i].right_fork = &data->forks[0];
		i++;
	}
}

int	init_mutexes(t_p *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->death_mutex, NULL) != 0)
		return (0);
	return (1);
}

int	init_simulation(t_p *data)
{
	data->dead = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->total_philos);
	if (!data->forks)
		return (0);
	data->philos = malloc(sizeof(t_philo) * data->total_philos);
	if (!data->philos)
	{
		free(data->forks);
		return (0);
	}
	if (!init_mutexes(data))
		return (0);
	data->start_time = get_time();
	init_philos(data);
	return (1);
}

int	start_threads(t_p *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, 
				philo_routine, &data->philos[i]) != 0)
			return (0);
		pthread_detach(data->philos[i].thread);
		i++;
	}
	return (1);
}
