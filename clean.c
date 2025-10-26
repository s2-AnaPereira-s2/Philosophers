#include "philo.h"

void cleanup(t_p *data)
{
    int i;

    i = 0;
    while (i < data->total_philos)
    {
        pthread_join(data->philos[i].thread, NULL);
        i++;
    }
    i = 0;
    while (i < data->total_philos)
    {
        pthread_mutex_destroy(&data->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&data->print_mutex);
    pthread_mutex_destroy(&data->death_mutex);
    
    free(data->forks);
    free(data->philos);
}
