/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:01 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:01 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Joins two strings into a new string
 *
 * @param	s1	The first string to join
 * @param	s2	The second string to join
 *
 * @return	A pointer to the new string or NULL on failure
 */
static char	*ft_strcpy(char *dst, char *src, int *len)
{
	int	j;
	int	i;

	i = *len;
	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	*len = i;
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s2)
		return (0);
	if (s1)
		while (s1[i])
			i++;
	if (s2)
		while (s2[j])
			j++;
	ptr = (char *)malloc(i + j + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	if (s1)
		ft_strcpy(ptr, (char *)s1, &i);
	ft_strcpy(ptr, (char *)s2, &i);
	ptr[i] = '\0';
	free(s1);
	s1 = NULL;
	return (ptr);
}
