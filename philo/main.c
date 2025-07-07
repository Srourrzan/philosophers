/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:10:17 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/07 13:07:46 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}

void	ft_clean_table(t_table *table)
{
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		status;

	status = 0;
	if (argc < 5 || argc > 6)
		return (ft_indicate_error("Usage: ./philo <num_philosophers> "
				"<time_to_die> <time_to_eat> "
				"<time_to_sleep> [num_times_must_eat]"));
	memset(&table, 0, sizeof(t_table));
	if (ft_init_table(&table, argc, argv) < 0)
		return (-1);
	if (ft_create_thread(&table) < 0)
		status = ft_indicate_error("Error: Failed "
				"to create threads");
	ft_monitor(&table);
	wait_philos(&table);
	ft_clean_table(&table);
	return (status);
}
