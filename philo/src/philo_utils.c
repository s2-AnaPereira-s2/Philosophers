/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:58:42 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/10/29 18:50:23 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

int	check_args(int argc)
{
	if (argc < 5)
	{
		printf("%s", "Please add: \
		\n-number of philosophers \
		\n-time to die \
		\n-time to eat\n-time to sleep \
		\n-(Optional) total number of meals each philo has to eat.\n");
		return (0);
	}
	if (argc > 6)
	{
		printf("%s", "Too many arguments. \
		\nPlease add:\n-number of philosophers \
		\n-time to die\n-time to eat\n-time to sleep \
		\n-(Optional) total number of meals each philo has to eat.\n");
		return (0);
	}
	return (1);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	print_message(t_philo *philo, char *message)
{
	long	current_time;

	pthread_mutex_lock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->death_mutex);
	if (!philo->data->dead)
	{
		current_time = get_time() - philo->data->start_time;
		printf("%ld %d %s\n", current_time, philo->id, message);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->dead)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (0);
}

void	die_lower_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->data->dead = 1;
	pthread_mutex_unlock(&philo->data->death_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return ;
}
