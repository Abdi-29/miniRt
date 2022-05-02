/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:52 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:52 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Set's an area of memory to the specified value
 *
 * @param	b	Array of bytes to modify
 * @param	c	Value to set each byte to
 * @param	len	Amount of bytes to set to the specified value
 *
 * @return	The initial value of the pointer to b
 */
char	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = b;
	while (len > 0)
	{
		len--;
		*tmp = c;
		tmp++;
	}
	return (b);
}
