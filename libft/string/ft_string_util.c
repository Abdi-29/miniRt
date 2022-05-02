/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string_util.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 17:03:19 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/28 17:03:19 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "string.h"

/**
 * Free a string
 *
 * @param	s	String to free
 */
void	free_string(t_string *s)
{
	free(s->s);
	free(s);
}

/**
 * Create a new string with len empty slots
 *
 * @param	len	Length of the new string
 *
 * @return	The new string or NULL on failure
 */
t_string	*create(int len)
{
	t_string	*s;

	s = ft_calloc(1, sizeof(t_string));
	if (s == NULL)
		return (NULL);
	s->s = ft_calloc(len, sizeof(char));
	if (s->s == NULL)
	{
		free(s);
		return (NULL);
	}
	s->empty = len;
	s->len = 0;
	return (s);
}
