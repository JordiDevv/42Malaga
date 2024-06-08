#include "libftprintf.h"

char	*ft_utohex(unsigned int n)
{
	char	*str;
	int	len;

	len = ft_ulen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (n)
	{
		str[len--] = hex_digits[n & 0xf];
		n >>= 4;
	}
	return (str);
}
