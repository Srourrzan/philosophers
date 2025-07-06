/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:10:17 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 17:00:23 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * TO DO LIST:
 * main data structure:
 * all data
 * - the configuration of the simulation
 * - pointer to the philosophers
 * - pointer to forks
 * - pointer to the mutexes
 * 
 */

int main(int argc, char **argv)
{
    t_table table;
    
    if (argc < 5 || argc > 6)
        return (ft_indicate_error("Usage: ./philo <num_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [num_times_must_eat]"));
    printf("valid arguments\n");
    memset(&table, 0, sizeof(t_table));
    if (ft_init_table(&table, argc, argv) < 0)
        return (ft_indicate_error("Error: Failed to initialize table"));
    printf("Table initialized successfully\n");
    if (ft_create_thread(table) < 0)
    {
        free(table.philosophers);
        pthread_mutex_destroy(&table.print_mutex);
        pthread_mutex_destroy(&table.simulation_mutex);
        return (ft_indicate_error("Error: Failed to create threads"));
    }
    printf("end\n");
    return (EXIT_SUCCESS);    
}
