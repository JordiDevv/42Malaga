void	ft_stradd(char *dst, char *src, int len)
{
	if (!src && !dst)
		return (NULL);
	while (len)
	{
		*dst++ = *src++;
		len--;
	}
}
