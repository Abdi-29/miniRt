/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:04 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:04 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Append src to dst for a total length of dstsize - 1
 *
 * @param	dst		String to append to
 * @param	src		String to append to dst
 * @param	dstsize	Max length of dst
 *
 * @return	The total size of the string that was attempted to be made
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size;

	size = ft_strlen(dst);
	if (dstsize < size)
		return (dstsize + ft_strlen(src));
	else
		ft_strlcpy(dst + size, src, dstsize - size);
	return (size + ft_strlen(src));
}
