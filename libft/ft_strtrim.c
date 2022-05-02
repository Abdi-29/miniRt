/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:14 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:14 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Removes set from the beginning and end of s1
 *
 * @param	s1	The string to trim
 * @param	set	The string to trim away
 *
 * @return	The malloced, trimmed string or NULL on failure
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trim;
	const char	*tmp;

	while (*s1 && ft_strrchr(set, *s1))
		s1++;
	tmp = s1;
	while (*s1)
		s1++;
	s1--;
	while (ft_strrchr(set, *s1) && s1 >= tmp)
		s1--;
	if (s1 <= tmp)
		return (ft_calloc(1, sizeof(char)));
	trim = ft_calloc((s1 - tmp + 2), sizeof(char));
	if (trim == 0)
		return (NULL);
	ft_strlcpy(trim, tmp, (s1 - tmp) + 2);
	return (trim);
}
