/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:15 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:15 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Get a substring from a string
 *
 * @param	s		String to get a substring from
 * @param	start	How far from the start of the string to start the substring
 * @param	len		Length of the substring
 *
 * @return	The substring from the string
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	max_len;

	while (start && *s)
	{
		s++;
		start--;
	}
	max_len = ft_strlen(s);
	if (len > max_len)
		len = max_len;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == 0)
		return (NULL);
	ft_strlcpy(substr, s, len + 1);
	return (substr);
}
