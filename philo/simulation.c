/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:00:43 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 22:45:36 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_is_dead(t_philosopher *philo)
{
    int is_dead;

    pthread_mutex_lock(&philo->table->simulation_status_lock);
    is_dead = !philo->table->simulation_status;
    pthread_mutex_unlock(&philo->table->simulation_status_lock);
    return (is_dead);
}

void ft_print_routine(t_philosopher *philo, char *str)
{
    long            now;
    
    now = ft_time_interval(philo->table);
    pthread_mutex_lock(&philo->table->print_lock);
    printf("%ld %d %s\n", now, philo->id, str);
    pthread_mutex_unlock(&philo->table->print_lock);
}

void    *ft_routine(void *philosopher)
{
    t_philosopher *philo;

    philo = (t_philosopher *)philosopher;
    while (1)
    {
        ft_print_routine(philo, "is thinking");
        pthread_mutex_lock(philo->left_fork);
        if (ft_is_dead(philo))
        {
            pthread_mutex_unlock(philo->left_fork);
            break;
        }
        ft_print_routine(philo, "has taken a fork");
        pthread_mutex_lock(philo->right_fork);
        if (ft_is_dead(philo))
        {
            pthread_mutex_unlock(philo->left_fork);
            pthread_mutex_unlock(philo->right_fork);
            break;
        }
        ft_print_routine(philo, "has taken a fork");
        ft_print_routine(philo, "is eating");
        pthread_mutex_lock(&philo->eating_time_lock);
        philo->last_eating_time = ft_time_interval(philo->table);
        pthread_mutex_unlock(&philo->eating_time_lock);
        usleep(philo->table->time_to_eat * 1000);
        if (ft_is_dead(philo))
        {
            pthread_mutex_unlock(philo->left_fork);
            pthread_mutex_unlock(philo->right_fork);
            break;
        }
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);
        ft_print_routine(philo, "is sleeping");
        usleep(philo->table->time_to_sleep * 1000);
        if (ft_is_dead(philo))
            break;
    }
    return (NULL);
}

int ft_create_thread(t_table *table)
{
    int i;

    // if (table->num_philosophers == 1)
    // {
    //     ft_print_status(&table->philosophers[0], "has taken a fork"); 
    //     return (0);
    // }
    i = 0;
    while (i < table->num_philosophers)
    {
        if (pthread_create(&table->philosophers[i].thread, NULL, &ft_routine, &table->philosophers[i]) != 0)
            return (1);
        i++;
    }
    return (0);
}

// int ft_simulation(t_philo *philo)
// {
//     int i;

//     if (philo->num_of_philos == 1)
//     {
//         ft_print_status(philo, "has taken a fork");
//         ft_usleep(philo->time_to_die);
//         return (0);
//     }
    
//     i = 0;
//     while (i < philo->num_of_philos)
//     {
//         if (pthread_create(&philo[i].thread, NULL, &ft_routine, &philo[i]) != 0)
//             return (1);
//         i++;
//     }
    
//     i = 0;
//     while (i < philo->num_of_philos)
//     {
//         pthread_join(philo[i].thread, NULL);
//         i++;
//     }
    
//     return (0);
// }