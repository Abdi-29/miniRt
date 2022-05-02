/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 17:59:47 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 17:59:47 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

/**
 * Prints string to standard output
 *
 * @param	str	String to print
 *
 * @return	Length of the printed string
 */
int	print_string(int fd, char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", fd));
	return (ft_putstr_fd(str, fd));
}

/**
 * Prints a character
 *
 * @param	c	Character to print
 *
 * @return	Amount of chars printed
 */
int	print_char(int fd, int c)
{
	return (ft_putchar_fd((char)c, fd));
}

/**
 * Prints a long
 *
 * @param	i	Long to print
 *
 * @return	Amount of characters printed
 */
int	print_long(int fd, long i)
{
	return (ft_putnbr_fd(i, fd));
}

/**
 * Prints a string and free's said string
 *
 * @param	str	String to print
 *
 * @return	Amount of characters printed
 */
int	print_str_free(int fd, char *str)
{
	int	len;

	if (!str)
		return (-1);
	len = print_string(fd, str);
	free(str);
	return (len);
}
