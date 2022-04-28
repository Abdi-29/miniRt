#include "libft.h"
#include "get_next_line.h"

char	*ft_free(char **remainder, int final)
{
	char	*output;

	if (!final)
		output = ft_strdup(*remainder);
	else
		output = NULL;
	free(*remainder);
	*remainder = NULL;
	return (output);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s_copy;

	i = 0;
	if (s == 0)
		return (0);
	s_copy = (char *)s;
	while (s_copy[i])
	{
		if (s_copy[i] == (char)c)
			return (s_copy + i);
		i++;
	}
	if (c == 0)
		return (s_copy + i);
	return (0);
}

char	*get_line(char *remainder, char *str)
{
	char	*output;
	int		len;

	len = ft_strlen(remainder) - ft_strlen(str) + 1;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (0);
	output = ft_strncpy(output, remainder, len);
	return (output);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*remainder;
	int			bytes_read;
	char		*output;
	char		*old_remainder;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (0);
	buffer[bytes_read] = 0;
	remainder = ft_strjoin(remainder, buffer);
	if (ft_strchr(remainder, '\n'))
	{
		output = get_line(remainder, ft_strchr(remainder, '\n'));
		old_remainder = remainder;
		remainder = ft_strdup(ft_strchr(remainder, '\n') + 1);
		free(old_remainder);
		return (output);
	}
	else if (bytes_read > 0)
		return (get_next_line(fd));
	else if (ft_strchr(remainder, '\0') && *remainder)
		return (ft_free(&remainder, 0));
	return (ft_free(&remainder, 1));
}
