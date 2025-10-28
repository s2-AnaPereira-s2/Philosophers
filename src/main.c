/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-pdos <ana-pdos@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:46:16 by ana-pdos          #+#    #+#             */
/*   Updated: 2025/10/27 14:08:17 by ana-pdos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_p	p;

	if (!check_args(argc))
		return (0);
	p.total_philos = atoi(argv[1]);
	p.tt_eat = atoi(argv[3]);
	p.tt_sleep = atoi(argv[4]);
	p.tt_die = atoi(argv[2]);
	if (argc == 6)
		p.total_meals = atoi(argv[5]);
	else
		p.total_meals = -1;
	if (p.total_philos <= 0 || p.tt_eat <= 0 || p.tt_sleep <= 0 
		|| p.tt_die <= 0 || (argc == 6 && p.total_meals <= 0))
	{
		printf("%s", "Invalid arguments\n");
		return (0);
	}
	if (!init_simulation(&p))
		return (1);
	if (!start_threads(&p))
		return (1);
	philos_check(&p);
	usleep(1000);
	cleanup(&p);
	return (0);
}
