/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:10:15 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 17:04:43 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_forks
{
    pthread_mutex_t	*forks;
    int				num_forks;
}	t_forks;

typedef struct s_philosopher
{
    int				id;
    int				times_eaten;
    long long        last_eating_time;
    t_forks        *left_fork;
    t_forks        *right_fork;
    pthread_mutex_t    eating_mutex;
    struct s_philosopher *next;
    pthread_t           thread;
}	t_philosopher;

typedef struct s_table
{
    int				num_philosophers;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				num_times_must_eat;
    int             thread_status; //Flag for thread synchronization
    int             simulation_over; // flag to indicate if the simulation is over
    long long        simulation_time; // flag to indicate the simulation start time
    t_philosopher	*philosophers; // list of philosophers
    t_forks			    *forks; // list of forks
    pthread_mutex_t	    print_mutex; // Mutex for synchronizing output
    pthread_mutex_t    simulation_mutex; // Mutex for synchronizing simulation (protecting shared state variables)
}	t_table;

#ifdef VIZ_MODE
# define VIZ 1
#else
# define VIZ 0
#endif

//stdutils.c file functions
int	ft_indicate_error(const char *message);
int	ft_atoi(const char *str);
int	ft_is_digit(int c);

//parsing.c file functions
int ft_parse_args(int argc, char **argv);

//table.c file functions
int ft_init_table(t_table *table, int argc, char **argv);

#endif