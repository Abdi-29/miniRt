#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*find;
	size_t			l;

	if (!s)
		return (0);
	l = ft_strlen(s);
	if (start > l)
		return (ft_strdup(""));
	if (len > l)
		len = l;
	find = (char *)malloc(len + 1);
	if (find == 0)
		return (0);
	ft_strlcpy(find, s + start, len + 1);
	return (find);
}	
