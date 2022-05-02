/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:05:38 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:05:38 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts a string that starts with a digit to an int
 *
 * @param 	str	Char array to convert
 *
 * @return 		Converted integer
 */
static int	convert(const char *str)
{
	int	res;

	if (!ft_isdigit(*str))
		return (0);
	res = (*str - '0') * -1;
	str++;
	while (ft_isdigit(*str))
	{
		res *= 10;
		res -= (*str - '0');
		str++;
	}
	return (res);
}

/**
 * Converts a string to an int
 *
 * @param	str	String to convert
 *
 * @return	The converted integer or 0 on failure
 * 	(keep in mind 0 could be the converted integer)
 */
int	ft_atoi(const char *str)
{
	int	negative;

	negative = -1;
	while (ft_iswhite_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = 1;
		str++;
	}
	return (convert(str) * negative);
}
