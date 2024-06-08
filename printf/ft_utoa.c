#include "libftprintf.h"

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int	len;

	len = ft_ulen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (if n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (--len >= 0 && n != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
