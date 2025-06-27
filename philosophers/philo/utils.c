/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 23:51:34 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/06/27 19:42:30 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_atoi(const char *str)
{
	char    sign;
	int		r;

	sign = 1;
	r = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		r = r * 10 + *str - 48;
		str++;
	}
	return (r * sign);
}

int ft_isdigit(char *arg)
{
	int i;

	i = 0;
	if (arg[0] == '-')
		i++;
	while(arg[i])
	{
		if (arg[i] > '9' || arg[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

void    ft_usleep(t_philo *philo, long time)
{
	long	beg;

	beg = get_time(0, "ACTUAL");
	while (!philo->table->someone_dead)
	{
		if (get_time(beg, "DIF") > time)
			return ;
	}
}

long    get_time(long start_time, char *condition)
{
	long			actual_time;
	long			time;
	struct timeval	tv;
	
	if (gettimeofday(&tv, NULL))
		return (EXIT_ERROR/*destroy_mutex(table, MSSG);*/);
	actual_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    if (!ft_strncmp(condition, "ACTUAL", 6))
        return (actual_time);
    else if (!ft_strncmp(condition, "DIF", 6))
    {
        time = actual_time - start_time;
        return (time);
    }
    else
        return (-1);
}
