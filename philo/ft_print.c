/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:33:29 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 23:50:18 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_routine(t_philo *philo, char *str)
{
	if (ft_is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->table->print_lock);
	printf("%ld %d %s\n", ft_time_interval(philo->table), philo->id, str);
	pthread_mutex_unlock(&philo->table->print_lock);
}
