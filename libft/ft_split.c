/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:56 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:56 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Free all array entries and itself
 *
 * @param	arr	Array to free
 *
 * @return	NULL
 */
static char	**clear_arr(char **arr)
{
	while (arr && *arr)
	{
		free(*arr);
		arr++;
	}
	free(arr);
	return (NULL);
}

/**
 * Copies all pointers from src to dst for n pointers
 *
 * @param	dst	Array to copy into
 * @param	src	Array to copy from
 * @param	n	Amount of pointers to copy
 *
 * @return The original value of dst
 */
static void	*ft_pointercpy(void *dst, void *src, size_t n)
{
	long	*tmp_dst;
	long	*tmp_src;

	tmp_dst = dst;
	tmp_src = src;
	while (n > 0)
	{
		n--;
		*tmp_dst = *tmp_src;
		tmp_dst++;
		tmp_src++;
	}
	return (dst);
}

/**
 * Calculates the length of an array, or if the array is 0 the amount of
 * 	characters a string has until it reaches 0 or the stop char
 *
 * @param	arr		Array to potentially get the length for
 * @param	s		String to potentially get the length for
 * @param	stop	Character to stop on if getting the length for the string
 *
 * @return	The length of the array or string
 */
static int	len(char **arr, char const *s, char stop)
{
	char		**tmp_arr;
	const char	*tmp_chr;

	if (arr != 0)
	{
		tmp_arr = arr;
		while (*tmp_arr)
			tmp_arr++;
		return ((int)(tmp_arr - arr));
	}
	else
	{
		tmp_chr = s;
		while (*tmp_chr && *tmp_chr != stop)
			tmp_chr++;
		return ((int)(tmp_chr - s));
	}
}

/**
 * Add a string to an array
 *
 * @param	arr	Existing array
 * @param	s	String to add
 *
 * @return	A new array containing a copy of the previous array with it's last
 * 	entry being the provided string
 */
static char	**add(char **arr, char *s)
{
	char	**newarr;
	int		arr_len;

	arr_len = 0;
	if (arr == 0)
		newarr = ft_calloc(2, sizeof(char *));
	else
	{
		arr_len = len(arr, 0, 0);
		newarr = ft_calloc(arr_len + 2, sizeof(char *));
		if (newarr == 0)
			return (clear_arr(arr));
		ft_pointercpy(newarr, arr, arr_len);
		free(arr);
	}
	*(newarr + arr_len) = s;
	return (newarr);
}

/**
 * Splits the string on the provided character and stores each section in the
 * 	array it returns
 *
 * @param	s	String to split
 * @param	c	Character to split on
 *
 * @return	A malloced array containing the string split on the character,
 * 	or NULL on failure
 */
char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*entry;

	arr = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == 0)
			break ;
		entry = ft_calloc((len(0, s, c) + 1), sizeof(char));
		if (entry == 0)
			return (clear_arr(arr));
		ft_memcpy(entry, (void *)s, len(0, s, c));
		arr = add(arr, entry);
		while (*s && (*s != c))
			s++;
	}
	if (arr == 0)
		return (ft_calloc(1, sizeof(char *)));
	return (arr);
}
