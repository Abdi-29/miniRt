#include "libft.h"

static int	ft_front(char *s1, char *set)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				counter += 1;
				i++;
				j = 0;
			}
			else
			{
				j++;
			}
		}
		break ;
	}
	return (counter);
}

static int	ft_end(char *s1, char *set)
{
	int	i;
	int	len;

	len = ft_strlen(s1) - 1;
	while (len > 0)
	{
		i = 0;
		while (set[i] && len > 0)
		{
			if (s1[len] == set[i])
			{
				len--;
				i = 0;
			}
			else
			{
				i++;
			}
		}
		break ;
	}
	return (len);
}

static char	*ft_copy(char *s1, char *copy, int i, int j)
{
	int	k;

	k = 0;
	while (i <= j)
	{
		copy[k] = s1[i];
		i++;
		k++;
	}
	copy[k] = '\0';
	return (copy);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*copy;
	int		j;

	if (!(s1 && set))
		return (0);
	i = ft_front((char *)s1, (char *)set);
	j = ft_end((char *)s1, (char *)set);
	if (i >= j)
	{
		len = 0;
	}
	else
	{
		len = j + 1 - i;
	}
	copy = malloc(len + 1);
	if (copy == 0)
		return (0);
	ft_copy((char *)s1, copy, i, j);
	return (copy);
}
