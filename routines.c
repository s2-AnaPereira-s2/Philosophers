/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:04:34 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/08/18 19:04:45 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void start_eating(t_philo *philo)
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

void eat(t_philo *philo)
{
    start_eating(philo);
    
    if (philo->data->total_philos > 1)
    {
        print_message(philo, "is eating");
        pthread_mutex_lock(&philo->data->death_mutex);
        philo->last_meal_time = get_time();
        philo->meals_eaten++;
        pthread_mutex_unlock(&philo->data->death_mutex);
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
        return;
    }
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
}

void sleeping(t_philo *philo)
{
    if (is_dead(philo))
        return;
    
    print_message(philo, "is sleeping");
    usleep(philo->data->tt_sleep * 1000);
}

void thinking(t_philo *philo)
{
    if (is_dead(philo))
        return;
    print_message(philo, "is thinking");
}

void *philo_routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        usleep((philo->data->tt_eat / 2) * 1000);
    while (!is_dead(philo))
    {
        eat(philo);
        if (philo->data->total_meals > 0 && 
            philo->meals_eaten >= philo->data->total_meals)
            break;
        if (is_dead(philo))
            break; 
        sleeping(philo);
        if (is_dead(philo))
            break;   
        thinking(philo);
    }
    return (NULL);
}


