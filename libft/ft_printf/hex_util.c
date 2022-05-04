/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex_util.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 17:59:42 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 17:59:42 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Converts a long to a string
 *
 * @param	res			String to fill
 * @param	nbr			Number to convert
 * @param	characters	Character array to use as base
 * @param	size		Location in string
 *
 * @return	The amount of characters entered in the filled string
 */
static int	recursion(char *res, long nbr, char *characters, int size)
{
	int	pos;
	int	base;

	base = ft_strlen(characters);
	if (!nbr)
		return (size);
	pos = size;
	size = recursion(res, nbr / base, characters, size + 1);
	res[size - pos - 1] = characters[nbr % base];
	return (size);
}

/**
 * Converts a unsigned long to a string
 *
 * @param	res			String to fill
 * @param	nbr			Number to convert
 * @param	characters	Character array to use as base
 * @param	size		Location in string
 *
 * @return	The amount of characters entered in the filled string
 */
static int	recursion_ul(char *res, unsigned long nbr, char *characters,
						int size)
{
	int	pos;
	int	base;

	base = ft_strlen(characters);
	if (!nbr)
		return (size);
	pos = size;
	size = recursion_ul(res, nbr / base, characters, size + 1);
	res[size - pos - 1] = characters[nbr % base];
	return (size);
}

/**
 * Get's an empty, null terminated string (starting with a prefix if given)
 * 	with a length of prefix length + 16
 *
 * @param	prefix	Prefix to use (give NULL for none)
 *
 * @return	A null terminated string with length prefix length + 16
 * 			NULL on failure to allocate
 */
static char	*get_base_str(char *prefix)
{
	char	*res;
	char	*tmp;
	int		pref_len;

	if (prefix)
		pref_len = ft_strlen(prefix);
	else
		pref_len = 0;
	res = ft_calloc(pref_len + 16 + 1, sizeof(char));
	if (!res)
		return (NULL);
	tmp = res;
	while (prefix && *prefix)
	{
		*tmp = *prefix;
		tmp++;
		prefix++;
	}
	return (res);
}

/**
 * Converts any base 10 number to any other base
 *
 * @param	nbr			Number to convert
 * @param	characters	Characters that make up the base
 * 	(this is assumed to be a valid base)
 * @param	prefix		Prefix for the result (can be NULL)
 * @param	max_len 	length of prefix + longest the resulting hex could be
 *
 * @return	a malloced string with the number in a new base
 */
char	*ft_get_base(long nbr, char *characters, char *prefix)
{
	char	*res;
	char	*tmp;

	res = get_base_str(prefix);
	if (!res)
		return (NULL);
	tmp = res;
	while (*tmp)
		tmp++;
	if (nbr)
		recursion(tmp, nbr, characters, 0);
	else
		*tmp = characters[0];
	return (res);
}

/**
 * Converts any base 10 unsigned number to any other base
 *
 * @param	nbr			Unsigned number to convert
 * @param	characters	Characters that make up the base
 * 	(this is assumed to be a valid base)
 * @param	prefix		Prefix for the result (can be NULL)
 * @param	max_len 	length of prefix + longest the resulting hex could be
 *
 * @return	a malloced string with the number in a new base
 */
char	*ft_get_base_ul(unsigned long nbr, char *characters, char *prefix)
{
	char	*res;
	char	*tmp;

	res = get_base_str(prefix);
	if (!res)
		return (NULL);
	tmp = res;
	while (*tmp)
		tmp++;
	if (nbr)
		recursion_ul(tmp, nbr, characters, 0);
	else
		*tmp = characters[0];
	return (res);
}
