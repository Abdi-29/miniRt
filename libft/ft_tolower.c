/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:16 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:16 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * Convert character to lowercase
 *
 * @param	c	The character to convert to lowercase
 *
 * @return	The lowercase variant of c
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
	return (c);
}
