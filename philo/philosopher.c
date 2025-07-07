/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:45:40 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/07 14:37:37 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_forks(t_table *table, t_philo *philo, int i)
{
	if (i == 0)
	{
		philo[i].left_fork = &table->forks[i];
		philo[i].right_fork = NULL;
	}
	else if ((i & 1) == 0)
	{
		philo[i].left_fork = &table->forks[(i + 1) % table->nb_philo];
		philo[i].right_fork = &table->forks[i];
	}
	else
	{
		philo[i].left_fork = &table->forks[i];
		philo[i].right_fork = &table->forks[(i + 1) % table->nb_philo];
	}
}

t_philo	*ft_init_philo(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * table->nb_philo);
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo) * table->nb_philo);
	i = 0;
	while (i < table->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].times_eaten = 0;
		philo[i].last_eating_time = 0;
		philo[i].eaten_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		philo[i].eating_time_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		set_forks(table, philo, i);
		philo[i].table = table;
		i++;
	}
	return (philo);
}

int	ft_create_thread(t_table *table)
{
	int	i;

	i = 0;
	if (!table)
		return (-1);
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL,
				&ft_routine, &table->philos[i]) != 0)
		{
			pthread_mutex_lock(&table->status_lock);
			table->status = 0;
			pthread_mutex_unlock(&table->status_lock);
			return (-1);
		}
		i++;
	}
	pthread_mutex_lock(&table->threads_ready_lock);
	table->start_time = ft_time_interval(table);
	table->threads_ready = 1;
	pthread_mutex_unlock(&table->threads_ready_lock);
	return (0);
}
