/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:51 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:51 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies the area of memory from src into dst
 *
 * @param	dst	The area of memory to copy src into
 * @param	src	The area of memory to copy into dst
 * @param	n	The amount of bytes to copy
 *
 * @return	The initial value of the pointer to dst
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp_dst;
	const char	*tmp_src;

	if (dst == src)
		return (dst);
	tmp_dst = dst;
	tmp_src = src;
	while (n > 0)
	{
		n--;
		*tmp_dst = *tmp_src;
		tmp_dst++;
		tmp_src++;
	}
	return (dst);
}
