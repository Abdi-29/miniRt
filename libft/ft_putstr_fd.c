/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:56 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:56 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/**
 * Writes a string to the specified file descriptor
 *
 * @param	s	String to write
 * @param	fd	File descriptor to write to
 *
 * @return	amount of characters written
 */
int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}
