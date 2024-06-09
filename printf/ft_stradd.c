#include "libftprintf.h"

void	ft_stradd(char *dst, char *src, int len)
{
	if (!src && !dst)
		return ;
	while (len)
	{
		*dst++ = *src++;
		len--;
	}
}
