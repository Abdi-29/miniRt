/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:01 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:01 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Joins two strings into a new string
 *
 * @param	s1	The first string to join
 * @param	s2	The second string to join
 *
 * @return	A pointer to the new string or NULL on failure
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*res;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	else if (s1 == 0)
		return (ft_strdup(s2));
	else if (s2 == 0)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (res == 0)
		return (NULL);
	res = ft_memcpy(res, (void *)s1, s1_len);
	ft_memcpy(res + s1_len, (void *)s2, s2_len);
	return (res);
}
