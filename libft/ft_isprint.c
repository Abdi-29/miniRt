/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:28 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:28 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * Check if a given character is printable
 *
 * @param	c	The character to be checked
 *
 * @return	1 if the character is printable, 0 if not
 */
int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
