/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:10:15 by rsrour            #+#    #+#             */
/*   Updated: 2025/07/06 23:56:13 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define ALLOCATE_FAILED "Error: Failed to allocate memory for "

typedef struct s_table	t_table;
typedef struct s_philosopher
{
	int						id;
	int						times_eaten;
	long long				last_eating_time;
	pthread_mutex_t			*left_fork;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			eating_time_lock;
	pthread_mutex_t			eaten_lock;
	pthread_t				thread;
	t_table					*table;
}	t_philo;

struct s_table
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_times_must_eat;
	int				status;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	status_lock;
	long			start_time;
};

int				ft_indicate_error(const char *message);
int				ft_atoi(const char *str);
int				ft_is_digit(int c);
long			ft_time_interval(t_table *table);

int				ft_validate_arg(char *arg);

int				ft_init_table(t_table *table, int argc, char **argv);
int				ft_is_dead(t_philo *philo);

int				ft_create_thread(t_table *table);
t_philo			*ft_init_philo(t_table *table);
void			ft_monitor(t_table *table);
void			ft_print_routine(t_philo *philo, char *str);
void			ft_clean_table(t_table *table);

#endif