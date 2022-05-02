/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_streq.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 18:30:54 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/09 18:30:54 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if two strings are the exact same
 *
 * @param	s1	First string
 * @param	s2	Second string
 *
 * @return	1 if the strings are the same, 0 if not
 */
int	ft_streq(const char *s1, const char *s2)
{
	if (s1 == s2)
		return (1);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (*s1 == *s2);
}
