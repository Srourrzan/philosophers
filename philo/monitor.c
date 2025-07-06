/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:00:46 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 22:51:28 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_monitor(t_table *table)
{
    int i;

    while(1)
    {
        i = 0;
        while (i < table->num_philosophers)
        {
            if (ft_time_interval(table) - table->philosophers[i].last_eating_time >= table->time_to_die)
            {
                table->simulation_status = 0;
                ft_print_routine(&table->philosophers[i], "died");
                return ;
            }
            if ()
            i++;
        }
    }
}
