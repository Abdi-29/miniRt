/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:08 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:08 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Finds the first occurrence of hte string needle in the string haystack
 *
 * @param	haystack	The string to look in
 * @param	needle		The string to look for
 * @param	len			The amount of characters to look through
 *
 * @return	The pointer to the first occurrence of needle in haystack,
 * 	or NULL if needle isn't in haystack
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack)
	{
		if (!ft_strncmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
		len--;
		if (len < needle_len)
			break ;
	}
	return (NULL);
}
