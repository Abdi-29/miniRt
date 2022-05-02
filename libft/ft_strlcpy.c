/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:05 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:05 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copy the dstsize - 1 characters from the string src into dst
 *
 * @param	dst		The string to copy into
 * @param	src		The string to copy from
 * @param	dstsize	The max size of the string
 *
 * @return	The length of src
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*tmp_src;
	char		*tmp_dst;

	if (dstsize == 0)
		return (ft_strlen(src));
	tmp_src = src;
	tmp_dst = dst;
	while (dstsize > 0 && *tmp_src)
	{
		dstsize--;
		*tmp_dst = *tmp_src;
		tmp_dst++;
		tmp_src++;
	}
	if (dstsize == 0)
		*(tmp_dst - 1) = 0;
	else
		*tmp_dst = 0;
	return (ft_strlen(src));
}
