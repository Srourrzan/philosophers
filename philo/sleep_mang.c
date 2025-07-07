/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_mang.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:41:53 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/07 14:31:35 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep_mang(t_table *table, long long ms)
{
	long	start;

	start = ft_time_interval(table);
	while (ft_time_interval(table) - start < ms && !ft_is_dead(table))
		usleep(100);
}

long	ft_time_interval(t_table *table)
{
	struct timeval	tv;
	long			now;

	gettimeofday(&tv, NULL);
	now = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (now - table->start_time);
}

void	ft_steady_ready_go(t_table *table)
{
	if (!table)
		return ;
	pthread_mutex_lock(&table->threads_ready_lock);
	while (!table->threads_ready)
	{
		pthread_mutex_unlock(&table->threads_ready_lock);
		usleep(100);
		pthread_mutex_lock(&table->threads_ready_lock);
	}
	pthread_mutex_unlock(&table->threads_ready_lock);
}
