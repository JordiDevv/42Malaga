#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdint.h>
# include <stdarg.h>
# include "jslib.h"

int	ft_hexlen(unsigned int n);
char	*ft_ptrtohex(void *p);
int	ft_ulen(unsigned int);
char	*ft_utohex(unsigned int n, int uppercase);
int	ft_printf(char const *str, ...);
void	ft_stradd(char *dst, char *src, int len);
char	*ft_utoa(unsigned int n);
void	ft_get_input(char **str, char **print, va_list args);
int	ft_size_of_print(char *str, va_list args_s);

#endif
