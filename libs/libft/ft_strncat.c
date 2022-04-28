char	*ft_strcat(char *dst, const char *src)
{
	int	j;
	int	i;

	j = 0;
	i = ft_strlen(dst);
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
