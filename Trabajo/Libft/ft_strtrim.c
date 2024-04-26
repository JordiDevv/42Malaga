#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (set[j])
	{
		while (s1[i] == set[j])
		{
			s1[i] = 0;
			i++;
			while (s1[i] != set[j] && set[j])
				j++;
		}
		i = ft_strlen(s1) - 2;
		j = 0;
		while (s1[i] == set[j])
		{
			s1[i] = 0;
			i--;
			while (s1[i] != set[j] && set[j])
				j++;
		}
	}
	s1 = malloc(ft_strlen(s1));
	return (s1);
}
