/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:38:12 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/08/18 19:02:58 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(int argc)
{
    if (argc < 5)
    {
        printf("%s", "Please add:\n-number of philosophers\n-time to eat\n-time to sleep\n-time to die\n-(Optional) total number of meals each philo has to eat.\n");
        return (0);
    }
    if (argc > 6)
    {
        printf("%s", "Too many arguments.\nPlease add:\n-number of philosophers\n-time to eat\n-time to sleep\n-time to die\n-(Optional) total number of meals each philo has to eat.\n");
        return (0);
    }
    return (1);
}

int enough_philos(t_p *p)
{
    if (p->total_philos < 2)
    {
        printf("%s", "You need at least 2 philosophers.\n");
        return (0);
    }
    return (1);
}

int forks_available(t_p *p)
{
    if (p->forks_num = p->forks_num - 2)
        return (0);
    return (1);
}


