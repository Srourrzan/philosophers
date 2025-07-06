/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:12:43 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 21:40:59 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_validate_arg(char *arg)
{
	int atoi_result;
	int i;

	if (!arg || !*arg)
		return (-1);
	i = 0;
	atoi_result = 0;
	while (arg[i] != '\0')
	{
		if (!ft_is_digit(arg[i]))
			return (-1); // Invalid character found
		i++;
	}
	atoi_result = ft_atoi(arg);
	if (atoi_result < 0)
		return (-1);
	return (atoi_result); // All characters are digits
}

// 0 numer of times eacho philosopher must eat means all dies (optional parameter)
int ft_parse_args(int argc, char **argv)
{
	int num_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_times_must_eat;
	
	if (!argv || !*argv)
		return (ft_indicate_error("Error: No arguments provided"));
	// Convert arguments to integers and check for validity
	num_times_must_eat = -1; // Default value for optional argument
	num_philosophers = ft_validate_arg(argv[1]);
	if (num_philosophers < 0)
		return (ft_indicate_error("Error: Invalid number of philosophers"));
	time_to_die = ft_validate_arg(argv[2]);
	if (time_to_die < 0)
		return (ft_indicate_error("Error: Invalid time to die"));
	time_to_eat = ft_validate_arg(argv[3]);
	if (time_to_eat < 0)	
		return (ft_indicate_error("Error: Invalid time to eat"));
	time_to_sleep = ft_validate_arg(argv[4]);
	if (time_to_sleep < 0)
		return (ft_indicate_error("Error: Invalid time to sleep"));
	if (argc == 6)
	{
		num_times_must_eat = ft_validate_arg(argv[5]);
		if (num_times_must_eat < 0)
			return (ft_indicate_error("Error: Invalid number of times each philosopher must eat"));
	}
	return (0); // All arguments are valid
}
