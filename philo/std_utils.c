/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:05:12 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 10:16:16 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_indicate_error(const char *message)
{
    if (message)
        printf("%s\n", message);
    return (-1);
}
