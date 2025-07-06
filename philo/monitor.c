/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:00:46 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/07 00:00:26 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_starving(t_philo *philo)
{
	long	now;
	int		is_dead;

	now = ft_time_interval(philo->table);
	pthread_mutex_lock(&philo->eating_time_lock);
	is_dead = now - philo->last_eating_time >= philo->table->time_to_die;
	pthread_mutex_unlock(&philo->eating_time_lock);
	if (is_dead)
	{
		pthread_mutex_lock(&philo->table->status_lock);
		philo->table->status = 0;
		pthread_mutex_unlock(&philo->table->status_lock);
		pthread_mutex_lock(&philo->table->print_lock);
		printf("%ld %d %s\n", ft_time_interval(philo->table),
			philo->id, "died");
		pthread_mutex_unlock(&philo->table->print_lock);
	}
	return (is_dead);
}

static int	check_full(t_philo *philo)
{
	int	is_full;

	if (philo->table->num_times_must_eat == -1)
		return (0);
	pthread_mutex_lock(&philo->eaten_lock);
	is_full = philo->times_eaten >= philo->table->num_times_must_eat;
	pthread_mutex_unlock(&philo->eaten_lock);
	return (is_full);
}

void	ft_monitor(t_table *table)
{
	int	i;
	int	nb_full;

	while (1)
	{
		i = 0;
		nb_full = 0;
		while (i < table->nb_philo)
		{
			if (check_starving(&table->philos[i]))
				return ;
			if (table->num_times_must_eat != -1)
				nb_full += check_full(&table->philos[i]);
			usleep(74);
			i++;
		}
		if (nb_full == table->nb_philo)
		{
			pthread_mutex_lock(&table->status_lock);
			table->status = 0;
			pthread_mutex_unlock(&table->status_lock);
			return ;
		}
	}
}
