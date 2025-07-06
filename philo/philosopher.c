/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:45:40 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 17:01:28 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philosopher *ft_init_philo()
{
    t_philosopher *philo;

    philo = malloc(sizeof(t_philosopher)); // or memeset if you want to initialize all fields
            //memset(&philo, 0, sizeof(t_philosopher)); // Optional: Initialize all fields to zero
    if (!philo)
        return (NULL);
    philo->id = 0; // Default ID, can be set later
    philo->times_eaten = 0;
    philo->left_fork = NULL; // Will be set when linked with other philosophers
    philo->right_fork = NULL; // Will be set when linked with other philosophers
    philo->next = NULL; // Initialize next pointer to NULL
    return (philo);
}
