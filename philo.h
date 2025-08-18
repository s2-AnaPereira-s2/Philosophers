/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:49:38 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/08/18 18:13:43 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>  

typedef struct s_p
{
	int	id;
	int	tt_eat;
	int	tt_sleep;
	int	tt_die;
	int	total_philos;
	int	total_meals;
	int	forks_num;
}	t_p;

int check_args(int argc);


#endif