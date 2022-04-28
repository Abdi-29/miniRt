#include "libft.h"

static int	ft_len(char const *s, char c)
{
	int	len;
	int	i;

	if (!s)
		return (0);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len++;
			while (s[i] != c && s[i])
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return (len + 1);
}

static int	ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
	}
	return (i);
}

static char	*ft_copy_word(char const *s, char c, char *word)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **to_free, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**s2;
	char	*tmp;
	int		j;

	s2 = malloc(ft_len(s, c) * sizeof(char *));
	if (!s2 || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!s[i])
			break ;
		tmp = malloc(ft_word_len(&s[i], c) * sizeof(char) + 1);
		s2[j] = ft_copy_word(&s[i], c, tmp);
		if (!s2)
			return (ft_free(s2, j));
		j++;
		i += ft_strlen(tmp);
	}
	s2[j] = 0;
	return (s2);
}
