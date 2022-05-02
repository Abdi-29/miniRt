/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string_operations.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 17:05:20 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/28 17:05:20 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#include "../libft/libft.h"

t_bool	ft_str_eq(t_string *s1, t_string *s2)
{
	if (s1->len != s2->len)
		return (false);
	if (ft_strncmp(s1->s, s2->s, s1->len))
		return (false);
	return (true);
}
