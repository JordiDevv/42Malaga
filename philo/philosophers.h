/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:04:30 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/09 17:53:04 by jsanz-bo         ###   ########.fr       */
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

# include <stdio.h>
# include <limits.h>

typedef struct s_conditions
{
	int n_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int n_eats;
}   t_conditions;

long long	ft_atoi(const char *str);
int			ft_isdigit(char *arg);

#endif