/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:00:43 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/07 14:37:16 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_table *table)
{
	int	is_dead;

	pthread_mutex_lock(&table->status_lock);
	is_dead = !table->status;
	pthread_mutex_unlock(&table->status_lock);
	return (is_dead);
}

int	left_a_forks(t_philo *philo, int l, int r)
{
	if (l)
		pthread_mutex_unlock(philo->left_fork);
	if (r)
		pthread_mutex_unlock(philo->right_fork);
	return (1);
}

int	eating(t_philo *philo)
{
	if (philo->left_fork == NULL)
		return (left_a_forks(philo, 1, 0));
	pthread_mutex_lock(philo->left_fork);
	if (ft_is_dead(philo->table))
		return (left_a_forks(philo, 1, 0));
	ft_print_routine(philo, "has taken a fork");
	if (philo->right_fork == NULL)
		return (left_a_forks(philo, 1, 0));
	pthread_mutex_lock(philo->right_fork);
	if (ft_is_dead(philo->table))
		return (left_a_forks(philo, 1, 1));
	ft_print_routine(philo, "has taken a fork");
	ft_print_routine(philo, "is eating");
	pthread_mutex_lock(&philo->eating_time_lock);
	philo->last_eating_time = ft_time_interval(philo->table);
	pthread_mutex_unlock(&philo->eating_time_lock);
	ft_sleep_mang(philo->table, philo->table->time_to_eat);
	if (ft_is_dead(philo->table))
		return (left_a_forks(philo, 1, 1));
	left_a_forks(philo, 1, 1);
	pthread_mutex_lock(&philo->eaten_lock);
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->eaten_lock);
	return (0);
}

void	*ft_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;
	ft_steady_ready_go(philo->table);
	if (philo->id & 1)
		usleep(753);
	while (1)
	{
		if (philo->id & 1)
			usleep(357);
		ft_print_routine(philo, "is thinking");
		if (eating(philo))
			break ;
		ft_print_routine(philo, "is sleeping");
		ft_sleep_mang(philo->table, philo->table->time_to_sleep);
		if (ft_is_dead(philo->table))
			break ;
	}
	return (NULL);
}
