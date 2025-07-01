/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:04:30 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/07/01 18:56:39 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define G "\033[32m"
# define R "\033[31m"
# define Y "\033[33m"
# define RE "\033[0m"

# define EXIT_ERROR 1
# define EXIT_SUCCESS 0
# define I_MAX "2147483647"

# define FORK_MSG "%ld: philo %d has taken a fork\n"
# define EAT_MSG "%ld: philo %d is eating\n"
# define SLEEP_MSG "%ld: philo %d is sleeping\n"
# define THINK_MSG "%ld: philo %d is thinking\n"
# define DEATH_MSG "%ld: philo %d has died\n"

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

struct  s_table;

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
	long			last_eating;
	struct s_table	*table;
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
	pthread_mutex_t	init_mutex;
	bool            init;
	pthread_mutex_t	death_mutex;
	bool			someone_dead;
	pthread_t		checker;
}   t_table;

int		ft_atoi(const char *str);
int		ft_isdigit(char *arg);
void    ft_usleep(t_philo *philo, long time);
long	get_time(long start_time, char *condition);
void	mutex_print(t_philo *philo, char *msg);

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		parse_args(int argc, char **args, t_conditions *conditions);

void	destroy_mutex(t_table *table, char *error_msg);

int	    init_table(t_table *table);

void    *philo_life(void *arg);
void	*checker_checks(void *arg);

#endif