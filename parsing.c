/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:12:43 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 10:24:00 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// 0 numer of times eacho philosopher must eat means all dies (optional parameter)
int ft_parse_args(int argc, char **argv)
{
    if (argc < 5 || argc > 6)
        return (ft_indicate_error("Error: Invalid number of arguments"));

    
    
    // Additional checks can be added here for specific argument requirements
    return (0);
}
