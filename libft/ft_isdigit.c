/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:27 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:27 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * Check if a given character is a digit
 *
 * @param	c	character to check
 *
 * @return 1 if the character is a digit, 0 if not
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
