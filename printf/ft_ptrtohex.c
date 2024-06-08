#include "libftprint.h"

char	*ft_ptrtohex(void *p)
{
	uintptr_t 	value;
	const char	*hex_digits;
	static char	buffer[2 + sizeof(void *) * 2 + 1];
	int		i;

	value = (uintptr_t)p;
	i = 2 + sizeof(void *) * 2 - 1;
	hex_digits = "0123456789abcdef";
	buffer[0] = '0';
	buffer[1] = 'x';
	while (i > 1)
	{
		buffer[i--] = hex_digits[value & 0xf];
		value >>= 4;
	}
	buffer[2 + sizeof(void *) * 2] = '\0';
	return (buffer);
}
