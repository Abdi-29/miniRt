/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:05:25 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:05:25 by sappunn       ########   odam.nl         */
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
int	print_string(char *str)
{
	if (!str)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(str, 1));
}

/**
 * Prints a character
 *
 * @param	c	Character to print
 *
 * @return	Amount of chars printed
 */
int	print_char(int c)
{
	return (ft_putchar_fd((char)c, 1));
}

/**
 * Prints a long
 *
 * @param	i	Long to print
 *
 * @return	Amount of characters printed
 */
int	print_long(long i)
{
	return (ft_putnbr_fd(i, 1));
}

/**
 * Prints a string and free's said string
 *
 * @param	str	String to print
 *
 * @return	Amount of characters printed
 */
int	print_str_free(char *str)
{
	int	len;

	if (!str)
		return (-1);
	len = print_string(str);
	free(str);
	return (len);
}
