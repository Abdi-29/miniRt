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

/**
 * Checks if nl contains a \n
 *
 * @param	nl	String to check
 *
 * @return	1 if a \n is found, 0 if not
 */
int	has_next_line(char *nl)
{
	if (nl == 0)
		return (0);
	while (*nl && *nl != '\n')
		nl++;
	if (*nl == '\n')
		return (1);
	return (0);
}

/**
 * Second part of the get_next_line function
 *
 * @param	fd		File descriptor we're reading from
 * @param	buffer	Buffer that contains text from file
 * @param	nl		String that contains all text we read attempting to get the
 * 					next new line so far
 * @param	len		Length of last buffer read
 *
 * @return A string ending in \n
 */
char	*get_next_line_2(int fd, char *buffer, char *nl, long len)
{
	if ((!len && !nl) || len < 0)
		return (NULL);
	else if (!len)
		return (ft_nl_substr(nl, buffer));
	nl = ft_strjoin_clear(nl, buffer, 1);
	if (!nl)
		return (NULL);
	while (len == 100 && !has_next_line(nl))
	{
		ft_memset(buffer, 0, ft_strlen_stop(buffer, 0));
		len = read(fd, buffer, 100);
		nl = ft_strjoin_clear(nl, buffer, 1);
		if (!nl)
			return (NULL);
	}
	return (ft_nl_substr(nl, buffer));
}

/**
 * Get a new line from a file
 *
 * @param	fd	file to look in
 *
 * @return	pointer	to the start of the new line (the char gets allocated)
 */
char	*get_next_line(int fd)
{
	char			*nl;
	long			len;
	static char		buffer[101];

	if (fd < 0 || fd >= 1024)
		return (NULL);
	nl = NULL;
	if (*buffer)
	{
		nl = ft_strjoin_clear(nl, buffer, 1);
		if (!nl)
			return (NULL);
	}
	if (has_next_line(nl))
		return (ft_nl_substr(nl, buffer));
	len = read(fd, buffer, 100);
	return (get_next_line_2(fd, buffer, nl, len));
}
