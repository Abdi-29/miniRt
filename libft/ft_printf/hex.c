/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 17:59:40 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 17:59:40 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

/**
 * Convert a number to hex in lowercase
 *
 * @param	nbr	Number to convert
 *
 * @return	The number as a string
 */
char	*get_hex_lower(long nbr)
{
	return (ft_get_base(nbr, "0123456789abcdef", 0));
}

/**
 * Convert a number to hex in uppercase
 *
 * @param	nbr	Number to convert
 *
 * @return	The number as a string
 */
char	*get_hex_upper(long nbr)
{
	return (ft_get_base(nbr, "0123456789ABCDEF", 0));
}

/**
 * Convert a pointer to hex in lowercase
 *
 * @param	nbr	pointer to convert
 *
 * @return	The pointer as a string
 */
char	*get_pointer(unsigned long nbr)
{
	return (ft_get_base_ul(nbr, "0123456789abcdef", "0x"));
}
