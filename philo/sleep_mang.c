/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_mang.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:41:53 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/07 13:07:30 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_sleep_mang(t_table *table, long long ms)
{
    long    start;

    start = ft_time_interval(table);
    while (ft_time_interval(table) - start < ms && !ft_is_dead(table))
        usleep(74);
}

long	ft_time_interval(t_table *table)
{
	struct timeval	tv;
	long			now;

	gettimeofday(&tv, NULL);
	now = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (now - table->start_time);
}
