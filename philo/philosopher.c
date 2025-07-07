/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:45:40 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/07 12:54:02 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		philo[i].left_fork = &table->forks[i];
		philo[i].right_fork = &table->forks[(i + 1) % table->nb_philo];
		if (i == 0)
		{
			philo[i].right_fork = &table->forks[i];
			philo[i].left_fork = &table->forks[(i + 1) % table->nb_philo];
		}
		philo[i].table = table;
		i++;
	}
	return (philo);
}

void *ft_1_philo(void *philosopher)
{
	t_philo *philo;

	philo = (t_philo *)philosopher;
	ft_print_routine(philo, "is thinking");
	ft_print_routine(philo, "has taken a fork");
	return (NULL);
}

int	ft_create_thread(t_table *table)
{
	int	i;

	i = 0;
	if (!table)
		return (-1);
	if (table->nb_philo == 1)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &ft_1_philo, &table->philos[i]) != 0)
			return (-1);
		return (0);
	}
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
	return (0);
}
