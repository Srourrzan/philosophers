/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:45:40 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 22:44:10 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher *ft_init_pholisophers(t_table *table)
{
    t_philosopher *philo;
    int i;

    philo = malloc(sizeof(t_philosopher) * table->num_philosophers); // or memeset if you want to initialize all fields
    if (!philo)
        return (NULL);
    memset(philo, 0, sizeof(t_philosopher) * table->num_philosophers); // Optional: Initialize all fields to zero
    i = 0;
    while (i < table->num_philosophers)
    {
        philo[i].id = i + 1; // Set philosopher ID starting from 1
        philo[i].times_eaten = 0; // Initialize times eaten to 0
        philo[i].last_eating_time = 0; // Initialize last eating time to 0
        philo[i].eating_time_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER; // Initialize mutex
        philo[i].left_fork = &table->forks[i]; // Initialize left fork mutex
        philo[i].right_fork = &table->forks[(i + 1) % table->num_philosophers]; // Initialize right fork mutex
        if (i == 0)
        {
            philo[i].right_fork = &table->forks[i]; // Initialize left fork mutex
            philo[i].left_fork = &table->forks[(i + 1) % table->num_philosophers]; 
        }
        philo[i].table = table;
        i++;
    }
    return (philo);
}
