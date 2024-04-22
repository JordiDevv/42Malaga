#include "libft.h"

void	*memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char)s = (unsigned char)c)
			return (s);
		n--;
	}
	return (NULL);
}
