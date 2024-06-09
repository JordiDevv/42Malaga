#include "libftprintf.h"

char	*ft_utohex(unsigned int n, int uppercase)
{
	char	*str;
	int	len;
	char	*hex_digits;

	if (uppercase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
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
