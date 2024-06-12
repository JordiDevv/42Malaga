/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:05:45 by jsanz-bo          #+#    #+#             */
/*   Updated: 2024/06/12 16:33:27 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_printf(char const *str, ...);
int     ft_casthex(int n, int u);
int	    ft_ptrtohex(void *p);
int     ft_puthex(unsigned long long n, int a, int u);
int     ft_putun(unsigned int n);
int     ft_putstr(char *s);
int     ft_putint(int n);
int     ft_putchar(int c);

#endif
