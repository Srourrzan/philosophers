/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:12:43 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 23:26:16 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_validate_arg(char *arg)
{
	int	atoi_result;
	int	i;

	if (!arg || !*arg)
		return (-1);
	i = 0;
	atoi_result = 0;
	while (arg[i] != '\0')
	{
		if (!ft_is_digit(arg[i]))
			return (-1);
		i++;
	}
	atoi_result = ft_atoi(arg);
	if (atoi_result < 0)
		return (-1);
	return (atoi_result);
}
