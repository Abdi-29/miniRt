/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:26 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:26 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * Check if a given character is a valid ascii character
 *
 * @param	c	character to check
 *
 * @return	1 if the character is ascii, 0 if not
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
