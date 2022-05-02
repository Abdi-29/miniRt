/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iswhite_space.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:29 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:29 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if a character is a whitespace
 *
 * @param	c	Character to check
 *
 * @return	1 if the character is whitespace, 0 if it's not
 */
int	ft_iswhite_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}
