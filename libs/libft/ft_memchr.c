#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_copy;

	i = 0;
	s_copy = (unsigned char *)s;
	while (n > i)
	{
		if (s_copy[i] == (unsigned char)c)
		{
			return (s_copy + i);
		}
		i++;
	}
	return (0);
}
