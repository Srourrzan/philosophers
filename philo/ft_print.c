/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:33:29 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/07 13:11:37 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_routine(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->table->print_lock);
	pthread_mutex_lock(&philo->table->status_lock);
	if (!philo->table->status)
	{
		pthread_mutex_unlock(&philo->table->status_lock);
		pthread_mutex_unlock(&philo->table->print_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->table->status_lock);		
	printf("%ld %d %s\n", ft_time_interval(philo->table), philo->id, str);
	pthread_mutex_unlock(&philo->table->print_lock);
}
