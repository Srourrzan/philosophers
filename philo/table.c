/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:01:37 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 22:41:02 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// typedef struct s_table
// {
//     int				num_philosophers;
//     int				time_to_die;
//     int				time_to_eat;
//     int				time_to_sleep;
//     int				num_times_must_eat;
//     int             thread_status; //Flag for thread synchronization
//     int             simulation_over; // flag to indicate if the simulation is over
//     long long        simulation_time; // flag to indicate the simulation start time
//     t_philosopher	*philosophers; // list of philosophers
//     t_forks			    *forks; // list of forks
//     pthread_mutex_t	    print_mutex; // Mutex for synchronizing output
//     pthread_mutex_t    simulation_mutex; // Mutex for synchronizing simulation (protecting shared state variables)
// }	t_table;



int ft_init_table(t_table *table, int argc, char **argv)
{
    table->num_philosophers = ft_validate_arg(argv[1]);
    table->time_to_die = ft_validate_arg(argv[2]);
    table->time_to_eat = ft_validate_arg(argv[3]);
    table->time_to_sleep = ft_validate_arg(argv[4]);
    // printf("num: %d, t2d: %d, t2e: %d, t2s: %d\n", 
    //     table->num_philosophers,
    //     table->time_to_die,
    //     table->time_to_eat,
    //     table->time_to_sleep
    // );
    if (argc == 6)
        table->num_times_must_eat = ft_validate_arg(argv[5]);
    else
        table->num_times_must_eat = -1;
    if (table->num_philosophers < 0 || table->num_philosophers < 0
        || table->time_to_die < 0 || table->time_to_eat < 0
    || table->time_to_sleep < 0)
        return (ft_indicate_error("Error: Invalid arguments provided"));
    table->print_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    table->simulation_status_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	table->simulation_status = 1;
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->num_philosophers);
	if (!table->forks)
		return (ft_indicate_error("Error: Failed to allocate memory for forks"));
	for (int i = 0; i < table->num_philosophers; i++)
		table->forks[i] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	table->philosophers = ft_init_pholisophers(table);
	if (!table->philosophers)
		return (ft_indicate_error("Error: Failed to allocate memory for philosophers"));
    table->start_time = 0;
	table->start_time = ft_time_interval(table);
	return (0);
}
