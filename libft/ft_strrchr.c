/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:13 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:13 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * Finds the first occurrence of c in s
 *
 * @param	s	String to look through
 * @param	c	Char to look for
 *
 * @return	The first location of c in *s, or NULL if there is none
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*mem;
	char	chr;

	mem = NULL;
	chr = (char) c;
	while (*s)
	{
		if (*s == chr)
			mem = (char *)s;
		s++;
	}
	if (*s == chr)
		mem = ((char *)s);
	return (mem);
}
