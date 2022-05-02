/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ends_with.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:05:45 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:05:45 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if a string ends with a specific suffix
 *
 * @param	str		String to check the suffix for
 * @param	suffix	Suffix to check for
 *
 * @return	1 if the string ends with the suffix, 0 if not
 */
int	ft_ends_with(char *str, char *suffix)
{
	int	len;

	len = ft_strlen(suffix);
	return (ft_strncmp(str + ft_strlen(str) - len, suffix, len) == 0);
}
