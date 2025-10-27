/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:02:37 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/10/27 18:14:22 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating(t_philo *philo)
{
	if (philo->data->total_philos == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork");
		while (!is_dead(philo))
			usleep(1000);
		return ;
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork");
	}
}

void	eat(t_philo *philo)
{
	start_eating(philo);
	if (philo->data->total_philos > 1)
	{
		pthread_mutex_lock(&philo->data->death_mutex);
		philo->last_meal_time = get_time();
		philo->meals_eaten++;
		pthread_mutex_unlock(&philo->data->death_mutex);
		print_message(philo, "is eating");
		if (is_dead(philo))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			return ;
		}
		usleep(philo->data->tt_eat * 1000);
	}
	if (philo->data->total_philos == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	if (is_dead(philo))
		return ;
	print_message(philo, "is sleeping");
	usleep(philo->data->tt_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	long	think_time;
	long	time_to_die;
	long	time_to_action;

	if (is_dead(philo))
		return ;
	print_message(philo, "is thinking");
	time_to_die = philo->data->tt_die - (get_time() - philo->last_meal_time);
	time_to_action = philo->data->tt_eat + philo->data->tt_sleep;
	if (time_to_action < time_to_die)
	{
		think_time = (time_to_die - time_to_action) / 2;
		if (think_time > 1)
			usleep((think_time - 1) * 1000);
	}
	else if (philo->data->total_philos % 2 != 0)
		usleep(1000);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->data->tt_eat * 1000);
	while (!is_dead(philo))
	{
		eat(philo);
		if (philo->data->total_meals > 0 
			&& philo->meals_eaten >= philo->data->total_meals)
			break ;
		if (is_dead(philo))
			break ;
		sleeping(philo);
		if (is_dead(philo))
			break ;
		thinking(philo);
	}
	return (NULL);
}
