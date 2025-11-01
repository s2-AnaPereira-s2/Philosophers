/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:49:38 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/10/29 18:52:11 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>  

typedef struct s_philo 
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_p		*data;
}	t_philo;

typedef struct s_p
{
	int				total_philos;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				total_meals;
	int				dead;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	t_philo			*philos;
}	t_p;

int		check_args(int argc);
long	get_time(void);
void	print_message(t_philo *philo, char *message);
int		is_dead(t_philo *philo);
void	*philo_routine(void *arg);
int		init_simulation(t_p *p);
int		start_threads(t_p *p);
void	philos_check(t_p *p);
void	cleanup(t_p *p);
void	die_lower_eat(t_philo *philo);

#endif
