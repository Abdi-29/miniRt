/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:52 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:52 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies the area of memory from src into dst but from the end to the beginning
 *
 * @param	dst	The area of memory to copy src into
 * @param	src	The area of memory to copy into dst
 * @param	len	The amount of bytes to copy
 */
static void	ft_memcpy_reverse(char *dst, const char *src, size_t len)
{
	while (len > 0)
	{
		len--;
		*dst = *src;
		dst--;
		src--;
	}
}

/**
 * Safely copy src into dst even if they overlap
 *
 * @param dst
 * @param src
 * @param len
 *
 * @return	The initial value of the pointer to dst
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == src)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, (void *) src, len);
	else
		ft_memcpy_reverse(dst + (len - 1), src + (len - 1), len);
	return (dst);
}
