/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:05:28 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:05:28 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "get_next_line.h"
#include "internal.h"
#include "../libft.h"
#define BUFFER_SIZE 1024

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

char	*ft_strncpy(char *dst, char *src, size_t n)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
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
