/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:01:37 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/07 13:46:11 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_locks(t_table *table)
{
	int		i;

	table->forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!table->forks)
		return (ft_indicate_error(ALLOCATE_FAILED"forks"));
	i = 0;
	while (i < table->nb_philo)
	{
		table->forks[i] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
		i++;
	}
	return (0);
}

int	ft_init_table(t_table *table, int argc, char **argv)
{
	table->nb_philo = ft_validate_arg(argv[1]);
	table->time_to_die = ft_validate_arg(argv[2]);
	table->time_to_eat = ft_validate_arg(argv[3]);
	table->time_to_sleep = ft_validate_arg(argv[4]);
	if (argc == 6)
		table->num_times_must_eat = ft_validate_arg(argv[5]);
	else
		table->num_times_must_eat = -1;
	if (table->nb_philo < 0 || table->nb_philo < 0 || table->time_to_die < 0
		|| table->time_to_eat < 0 || table->time_to_sleep < 0)
		return (ft_indicate_error("Error: Invalid arguments provided"));
	table->print_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	table->status_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	table->threads_ready_lock = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	table->status = 1;
	table->threads_ready = 0;
	if (ft_init_locks(table))
		return (1);
	table->philos = ft_init_philo(table);
	if (!table->philos)
		return (ft_indicate_error(ALLOCATE_FAILED"philosophers"));
	table->start_time = 0;
	return (0);
}
