/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_starts_with.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:57 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:57 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if a string starts with a specific prefix
 *
 * @param	str		String to check the prefix for
 * @param	prefix	Prefix to check for
 *
 * @return	1 if the string starts with the prefix, 0 if not
 */
int	ft_starts_with(char *str, char *prefix)
{
	return (ft_strncmp(str, prefix, ft_strlen(str)) == 0);
}
