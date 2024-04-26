#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) - 1);
	if (!str)
		return (NULL);
	str = ft_strlcat(s1, s2, ft_strlen(s2));
	return (str);
}
