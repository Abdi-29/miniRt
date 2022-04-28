#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d_copy;
	unsigned char		*s_copy;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	d_copy = (unsigned char *)dst;
	s_copy = (unsigned char *)src;
	while (n > i)
	{
		d_copy[i] = s_copy[i];
		i++;
	}
	return (dst);
}
