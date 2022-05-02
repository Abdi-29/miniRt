/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:50 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:50 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares two area's of memory and returns the difference if it finds it
 * 	or if there is no difference in the entire length of the areas of memory 0
 *
 * @param	s1	First area of memory
 * @param	s2	Second area of memory
 * @param	n	The amount of bytes to compare
 *
 * @return	The difference between the first two different bytes found within
 * 	n bytes or 0 if no difference is found
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmps1;
	const unsigned char	*tmps2;

	if (n == 0)
		return (0);
	tmps1 = (const unsigned char *)s1;
	tmps2 = (const unsigned char *)s2;
	while (*tmps1 == *tmps2 && n > 1)
	{
		tmps1++;
		tmps2++;
		n--;
	}
	return (*tmps1 - *tmps2);
}
