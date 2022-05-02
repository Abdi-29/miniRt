/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:48 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:48 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Find the first occurrence of the byte c in a given byte array
 *
 * @param	s	String to look in
 * @param	c	Character to find
 * @param	n	Amount of bytes to look for
 *
 * @return	A pointer to the first occurrence of c
 * 	or NULL if c isn't found in n bytes
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmps;
	unsigned char		c_char;

	c_char = c;
	tmps = (const unsigned char *) s;
	while (n)
	{
		if (*tmps == c_char)
			return ((void *) tmps);
		tmps++;
		n--;
	}
	return (NULL);
}
