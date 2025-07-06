/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:10:15 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 22:44:10 by rsrour           ###   ########.fr       */
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
# include <time.h>
# include <unistd.h>

typedef struct s_table t_table;
typedef struct s_philosopher
{
    int				id;
    int				times_eaten;
    long long        last_eating_time;
    pthread_mutex_t        *left_fork;
    pthread_mutex_t        *right_fork;
    pthread_mutex_t    eating_time_lock;
    struct s_philosopher *next;
    pthread_t           thread;
    t_table             *table;
}	t_philosopher;

struct s_table
{
    int				num_philosophers;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
    int				num_times_must_eat;
    // int             thread_status; //Flag for thread synchronization
    int             simulation_status; // flag to indicate if the simulation is over
    t_philosopher	*philosophers; // list of philosophers
    pthread_mutex_t			    *forks; // list of forks
    pthread_mutex_t	    print_lock; // Mutex for synchronizing output
    pthread_mutex_t    simulation_status_lock; // Mutex for synchronizing simulation (protecting shared state variables)
    long            start_time;
};

#ifdef VIZ_MODE
# define VIZ 1
#else
# define VIZ 0
#endif

//stdutils.c file functions
int	ft_indicate_error(const char *message);
int	ft_atoi(const char *str);
int	ft_is_digit(int c);
long ft_time_interval(t_table *table);

//parsing.c file functions
int ft_parse_args(int argc, char **argv);
int ft_validate_arg(char *arg);

//table.c file functions
int ft_init_table(t_table *table, int argc, char **argv);

int ft_create_thread(t_table *table);
t_philosopher *ft_init_pholisophers(t_table *table);
void ft_monitor(t_table *table);
void ft_print_routine(t_philosopher *philo, char *str);
void ft_clean_table(t_table *table);

#endif