/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:00 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:00 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Duplicates a string
 *
 * @param	s1	String to duplicate
 *
 * @return	A pointer to the copy of s1 or NULL on failure
 */
char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	strlen;

	strlen = ft_strlen(s1);
	res = ft_calloc(strlen + 1, sizeof(char));
	if (res == 0)
		return (res);
	ft_memcpy(res, (void *)s1, strlen);
	return (res);
}
