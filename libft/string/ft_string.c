/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 15:33:21 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/28 15:33:21 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "string.h"
#include "string_internal.h"

/**
 * Duplicate a string
 *
 * @param	s	String to duplicate
 *
 * @return	New string with the same data as s
 */
t_string	*dup_string(t_string *s)
{
	t_string	*new;

	if (s == NULL)
		return (NULL);
	new = create(s->len + s->empty);
	if (new == NULL)
		return (NULL);
	new->len = s->len;
	new->empty = s->empty;
	ft_strlcpy(new->s, s->s, s->len);
	return (new);
}

/**
 * Create a string from a char array
 *
 * @param	arr	Array to create string from
 *
 * @returm	String with data from array or NULL on failure
 */
t_string	*init_string(char *arr)
{
	t_string	*s;
	int			arr_len;

	if (arr == NULL)
		arr_len = 0;
	else
		arr_len = ft_strlen(arr);
	s = create(arr_len + 100);
	if (s == NULL)
		return (NULL);
	s->len = arr_len;
	s->empty -= arr_len;
	if (arr == NULL)
		return (s);
	ft_strlcpy(s->s, arr, arr_len + 1);
	return (s);
}
