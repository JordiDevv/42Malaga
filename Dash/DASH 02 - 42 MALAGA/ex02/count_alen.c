/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:07:36 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/03/28 12:57:30 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	count_alen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 'a')
		i++;
	return (i);
}
