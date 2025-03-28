/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:21:39 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/03/28 12:55:57 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	repeat_letter(char *str, int i)
{
	char	l;

	l = str[i];
	while (--i > -1)
	{
		if (str[i] == l)
			return (1);
	}
	return (0);
}

int	more_instances(char *str, int i)
{
	int	has;

	has = 0;
	while (str[++i])
	{
		if (!repeat_letter(str, i) && ((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
			has = 1;
	}
	return (has);
}

void	print_instances(char *str, int i, char l)
{
	int	n;

	n = 0;
	while (str[i])
	{
		if (str[i] == l)
			n++;
		i++;
	}
	printf("%d%c", n, l);
}

void	iterate_str(char *str)
{
	int		i;
	char	l;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (!repeat_letter(str, i))
			{
				l = str[i];
				print_instances(str, i, l);
				if (more_instances(str, i))
					printf(", ");
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2 || (argc == 2 && !argv[1][0]))
	{
		write (1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			argv[1][i] += 32;
		i++;
	}
	iterate_str(argv[1]);
	printf("\n");
	return (0);
}
