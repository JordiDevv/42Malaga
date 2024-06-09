#include "libftprintf.h"

static void	ft_get_input2(char **str, char **print, va_list args)
{
	char	*s;

	if (**str == 'u')
	{
		s = ft_utoa(va_arg(args, unsigned int));
		ft_stradd(*print, s, ft_strlen(s));
		(*print) += ft_strlen(s);
                free(s);
	}
	else if (**str == 'X' || **str == 'x')
        {
                s = ft_utohex(va_arg(args, unsigned int), **str == 'X');
                ft_stradd(*print, s, ft_strlen(s));
		(*print) += ft_strlen(s);
                free(s);
        }
        else if (**str == '%')
                *(*print)++ = '%';
}

void	ft_get_input(char **str, char **print, va_list args)
{
	char	*s;

	if (**str == 'c')
		*(*print)++ = (char)va_arg(args, int);
	else if (**str == 's')
	{
		s = va_arg(args, char *);
		ft_stradd(*print, s, ft_strlen(s));
		(*print) += ft_strlen(s);
	}
	else if (**str == 'p')
	{
		s = ft_ptrtohex(va_arg(args, void *));
		ft_stradd(*print, s, ft_strlen(s));
		(*print) += ft_strlen(s);
	}
	else if (**str == 'd' || **str == 'i')
	{
		s = ft_itoa(va_arg(args, int));
		ft_stradd(*print, s, ft_strlen(s));
		(*print) += ft_strlen(s);
		free(s);
	}
	else
		ft_get_input2(str, print, args);
	(*str)++;
}

static int      ft_get_size(char *str_cpy, va_list args_s)
{
        if (*str_cpy == 'c')
        {
                va_arg(args_s, int);
                return (1);
        }
        else if (*str_cpy == 's')
                return (ft_strlen(va_arg(args_s, char *)));
        else if (*str_cpy == 'p')
        {
                va_arg(args_s, void *);
                return (2 + sizeof(void *) * 2);
        }
        else if (*str_cpy == 'd' || *str_cpy == 'i')
                return (ft_intlen(va_arg(args_s, int)));
        else if (*str_cpy == 'u')
                return (ft_ulen(va_arg(args_s, unsigned int)));
        else if (*str_cpy == '%')
                return (1);
        else if (*str_cpy == 'X' || *str_cpy == 'x')
                return (ft_hexlen(va_arg(args_s, unsigned int)));
        return (0);
}

int      ft_size_of_print(char *str, va_list args_s)
{
        int     size;

        size = 0;
        while (*str)
        {
                if (*str == '%')
                {
                        str++;
                        size += ft_get_size(str, args_s);
                }
                else
                        size++;
                str++;
        }
        return (size);
}
