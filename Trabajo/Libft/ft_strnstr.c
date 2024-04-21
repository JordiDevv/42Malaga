char	*ft_strnstr(const char *, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!(*little))
		return (big);
	while (len > 0)
	{
		if (*big == *little)
		{
			while (big[i] == little[i])
			{
				if (!(little[i + 1] && big[i + 1] < 33))
					return (little);
				i++;
			}
			i = 0;
		}
		len--;
	}
	return (NULL);
}
