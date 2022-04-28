#include "libft.h"

static char	*ft_strcpy(char *dst, char *src, int *len)
{
	int	j;
	int	i;

	i = *len;
	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i += 1;
		j++;
	}
	*len = i;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		tot_len;
	char	*ptr;

	if (!(s1 && s2))
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	tot_len = i + j;
	ptr = (char *)malloc(tot_len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	if (s1 == 0)
		return ((char *)s2);
	if (s2 == 0)
		return ((char *)s1);
	ft_strcpy(ptr, (char *)s1, &i);
	ft_strcpy(ptr, (char *)s2, &i);
	ptr[i] = '\0';
	return (ptr);
}
