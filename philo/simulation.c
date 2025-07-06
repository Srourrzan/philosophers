/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:00:43 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 23:57:21 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_philo *philo)
{
	int	is_dead;

	pthread_mutex_lock(&philo->table->status_lock);
	is_dead = !philo->table->status;
	pthread_mutex_unlock(&philo->table->status_lock);
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
	pthread_mutex_lock(philo->left_fork);
	if (ft_is_dead(philo))
		return (left_a_forks(philo, 1, 0));
	ft_print_routine(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	if (ft_is_dead(philo))
		return (left_a_forks(philo, 1, 1));
	ft_print_routine(philo, "has taken a fork");
	ft_print_routine(philo, "is eating");
	pthread_mutex_lock(&philo->eating_time_lock);
	philo->last_eating_time = ft_time_interval(philo->table);
	pthread_mutex_unlock(&philo->eating_time_lock);
	usleep(philo->table->time_to_eat * 1000);
	if (ft_is_dead(philo))
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
	while (1)
	{
		if (philo->id & 1)
			usleep(269);
		ft_print_routine(philo, "is thinking");
		if (eating(philo))
			break ;
		ft_print_routine(philo, "is sleeping");
		usleep(philo->table->time_to_sleep * 1000);
		if (ft_is_dead(philo))
			break ;
	}
	return (NULL);
}

int	ft_create_thread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_create(&table->philos[i].thread, NULL,
				&ft_routine, &table->philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
