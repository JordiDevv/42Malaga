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

# include <stdint.h>
# include <stdarg.h>
# include "jslib/jslib.h"

int		ft_hexlen(unsigned int n);
char	*ft_ptrtohex(void *p);
int		ft_ulen(unsigned int n);
char	*ft_utohex(unsigned int n, int uppercase);
int		ft_printf(char const *str, ...);
void	ft_stradd(char *dst, char *src, int len);
char	*ft_utoa(unsigned int n);
void	ft_get_input(char **str, char **print, va_list args);
int		ft_size_of_print(char *str, va_list args_s);

#endif
