/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:04:30 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/12 19:07:05 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define G "\033[32m"
# define R "\033[31m"
# define Y "\033[33m"
# define RE "\033[0m"

# define EXIT_ERROR 1
# define EXIT_SUCCES 0
# define I_MAX "2147483647"

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_conditions
{
	int n_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int n_eats;
}   t_conditions;

typedef struct s_philo
{
	int				id;
    pthread_t		thread;
	pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
	long			time_on_action;
    t_table			*table;
    int				times_eaten;
}   t_philo;

typedef struct s_table
{
	t_conditions	conditions;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_mutex_t	print_mutex;
	struct	timeval	tv;
    long			start_time;
    bool			someone_died;
    pthread_mutex_t	death_mutex;
}   t_table;

int		ft_atoi(const char *str);
int		ft_isdigit(char *arg);

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		parse_args(int argc, char **args, t_conditions *conditions);

void	destroy_mutex(t_table *table, char *error_mssg);

#endif