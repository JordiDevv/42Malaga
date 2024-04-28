#include "libft.h"

static int	ft_numlen(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int		len;

	len = ft_numlen(n);
	str = (malloc(len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	str[len] = '\0';
	while (--len >= 0 && n != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
