/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:16 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:16 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * Convert character to uppercase
 *
 * @param	c	The character to convert to uppercase
 *
 * @return	The uppercase variant of c
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	return (c);
}
