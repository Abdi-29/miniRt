#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b_copy;

	i = 0;
	b_copy = (unsigned char *)b;
	while (len > i)
	{
		b_copy[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
