/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:49:26 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/08/18 19:03:48 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_p p;
    
    if (!check_args(argc))
        return (0);  
    p.total_philos = atoi(argv[1]);
    p.tt_eat = atoi(argv[2]);
    p.tt_sleep = atoi(argv[3]);
    p.tt_die = atoi(argv[4]);
    if (argc == 6)
        p.total_meals = atoi(argv[5]);
    else
        p.total_meals = -1;
    if (p.total_philos <= 0 || p.tt_eat <= 0 || p.tt_sleep <= 0 || p.tt_die <= 0 || (argc == 6 && p.total_meals <= 0))
    {
        printf("%s", "Invalid arguments\n");
        return (0);
    }
    if (!enough_philos(&p))
        return (0);
    p.forks_num = p.total_philos;
    return (1);
}
