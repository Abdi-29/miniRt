/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:07 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:07 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * Compares s1 to s2 and returns the difference if there is one
 *
 * @param	s1	String to compare to s2
 * @param	s2	String to compare to s1
 * @param	n	Amount of characters to compare
 *
 * @return	The difference between the first different chars or 0 if there is
 * 	no difference
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*tmps1;
	const unsigned char	*tmps2;

	if (n == 0)
		return (0);
	tmps1 = (const unsigned char *)s1;
	tmps2 = (const unsigned char *)s2;
	while (*tmps1 == *tmps2 && *tmps1 && *tmps2 && n > 1)
	{
		tmps1++;
		tmps2++;
		n--;
	}
	return (*tmps1 - *tmps2);
}
