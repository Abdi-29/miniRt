/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:57 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:57 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Finds the first occurrence of the character c in the string s
 *
 * @param	s	String to look through
 * @param	c	Character to look for
 *
 * @return	A pointer to the first location of c in s or NULL
 */
char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char) c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (*s == chr)
		return ((char *)s);
	return (NULL);
}
