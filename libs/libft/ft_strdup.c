#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s_copy;
	int		len;
	int		i;

	len = ft_strlen(s1);
	s_copy = (char *)malloc(len * sizeof(char) + 1);
	if (s_copy == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		s_copy[i] = s1[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
