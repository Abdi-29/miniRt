/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:05:36 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:05:36 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <wchar.h>
#include "../libft.h"

/**
 * Get's the length of a string or the length until the first occurrence of stop
 *
 * @param	str		String to get length for
 * @param	stop	Character to stop on
 *
 * @return	Length of the string until stop or \0
 */
size_t	ft_strlen_stop(const char *str, char stop)
{
	const char	*tmp;

	if (!str)
		return (0);
	tmp = str;
	while (*tmp && *tmp != stop)
		tmp++;
	return (tmp - str);
}

/**
 * Get's a substring from nl starting at pos 0 and ending at the first \n
 *
 * @param	nl		Variable that contain the text
 * @param	buffer	Variable to store remainder of nl in
 *
 * @return	A new string that ends in a \n
 */
char	*ft_nl_substr(void *nl, char *buffer)
{
	char	*substr;
	size_t	len;

	len = ft_strlen_stop(nl, '\n');
	substr = malloc((len + 2) * sizeof(char));
	if (substr == 0)
		return (NULL);
	ft_memset(substr, 0, len + 2);
	ft_memcpy(substr, nl, len + 1);
	ft_memcpy(buffer, nl + len + 1, ft_strlen_stop(nl, 0) - len);
	free(nl);
	return (substr);
}

/**
 * Joins a string and clears str if clear is not 0
 *
 * @param	nl		Variable containing new line
 * @param	str		Variable containing buffer
 * @param	clear	Boolean indicating if buffer should be cleared
 *
 * @return	The new nl (nl + str)
 */
char	*ft_strjoin_clear(char *nl, char *str, int clear)
{
	int		nl_len;
	int		str_len;
	char	*res;

	if (!nl && !str)
		return (NULL);
	else if (!str)
		return (nl);
	nl_len = ft_strlen_stop(nl, 0);
	str_len = ft_strlen_stop(str, 0);
	res = malloc((nl_len + str_len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	ft_memset(res, 0, nl_len + str_len + 1);
	if (nl_len)
		ft_memcpy(res, (void *)nl, nl_len);
	ft_memcpy(res + nl_len, (void *)str, str_len);
	if (nl)
		free(nl);
	if (clear)
		ft_memset(str, 0, ft_strlen_stop(str, 0));
	return (res);
}
