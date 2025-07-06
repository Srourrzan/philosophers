/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:01:37 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 16:27:01 by rsrour           ###   ########.fr       */
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
//     t_philosopher	*philosophers;
//     pthread_mutex_t	print_mutex;
// }	


int ft_init_table(int argc, char **argv)
{
    t_table *table;

    table = malloc(sizeof(t_table));
    if (!table)
    {
        printf("Error: Memory allocation failed for table\n");
        return (NULL);   
    }
    table->num_philosophers = ft_validate_arg(argv[1]);
    if (table->num_philosophers < 0)
        return (ft_indicate_error("Error: Invalid number of philosophers"));
    table->time_to_die = ft_validate_arg(argv[2]);
    if (table->time_to_die < 0)
        return (ft_indicate_error("Error: Invalid time to die"));
    table->time_to_eat = ft_validate_arg(argv[3]);
    if (table->time_to_eat < 0)
        return (ft_indicate_error("Error: Invalid time to eat"));
    table->time_to_sleep = ft_validate_arg(argv[4]);
    if (table->time_to_sleep < 0)
        return (ft_indicate_error("Error: Invalid time to sleep"));
    
    table->num_times_must_eat = -1; // Default value for optional argument
    if (argc == 6)
    {
        table->num_times_must_eat = ft_validate_arg(argv[5]);
        if (table->num_times_must_eat < 0)
            return (ft_indicate_error("Error: Invalid number of times must eat"));
    }
    
    pthread_mutex_init(&table->print_mutex, NULL);
    return (0);
}