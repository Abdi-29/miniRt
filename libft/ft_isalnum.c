/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:07:00 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:07:00 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if a given character is a digit or a letter in the alphabet
 *
 * @param	c	The character to check
 *
 * @return	1 if the character is a digit or letter, 0 if not
 */
int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
