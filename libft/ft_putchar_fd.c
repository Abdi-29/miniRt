/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:57 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:57 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * Writes a char to the specified file descriptor
 *
 * @param	c	Character to write
 * @param	fd	File descriptor to write to
 *
 * @return	amount of characters written
 */
int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
