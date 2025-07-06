/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mian.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:10:17 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 15:09:43 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * TO DO LIST:
 * main data structure:
 * all data
 * - the configuration of the simulation
 * - pointer to the philosophers
 * - pointer to forks
 * - pointer to the mutexes
 * 
 */

#include "philo.h"


int main(int argc, char **argv)
{
    if (ft_parse_args(argc, argv) < 0)
        return (-1);
    return (EXIT_SUCCESS);    
}