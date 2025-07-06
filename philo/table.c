/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:01:37 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 17:03:01 by rsrour           ###   ########.fr       */
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
    table = malloc(sizeof(t_table));
    if (!table)
        return (ft_indicate_error("Error: Memory allocation failed for table"));   
    table->num_philosophers = ft_validate_arg(argv[1]);
    table->time_to_die = ft_validate_arg(argv[2]);
    table->time_to_eat = ft_validate_arg(argv[3]);
    table->time_to_sleep = ft_validate_arg(argv[4]);
    if (argc == 6)
        table->num_times_must_eat = ft_validate_arg(argv[5]);
    else
        table->num_times_must_eat = -1;
    if (table->num_philosophers < 0 || table->num_philosophers < 0
        || table->time_to_die < 0 || table->time_to_eat < 0
    || table->time_to_sleep < 0 || table->num_times_must_eat < 0)
    {
        free(table);
        return (ft_indicate_error("Error: Invalid arguments provided"));
    }
    pthread_mutex_init(&table->print_mutex, NULL);
    return (0);
}
