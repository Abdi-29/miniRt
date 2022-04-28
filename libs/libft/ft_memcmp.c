#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	i = 0;
	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_copy[i] != s2_copy[i])
		{
			return (s1_copy[i] - s2_copy[i]);
		}
		i++;
	}
	return (0);
}
