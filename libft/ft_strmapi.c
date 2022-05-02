/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:06 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:06 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterates through a given string to execute a given function
 * 	on each char and store the result of that entry in a new string
 *
 * @param	s	The string to iterate through
 * @param	f	The function to apply to each char
 *
 * @return	A new string that contains a version of the string that had
 * the function f applied to all of it's chars
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (str == 0)
		return (NULL);
	while (*(s + i))
	{
		*(str + i) = f(i, *(s + i));
		i++;
	}
	return (str);
}
