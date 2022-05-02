/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:29 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:29 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calculates the amount of characters that would be needed to store the given
 * 	integer as a char array
 *
 * @param	nb	Number to get the length of
 *
 * @return	The length of the number (aka amount of characters it would use)
 */
static long	long_len(long nb)
{
	long	len;

	len = 0;
	while (nb > 9 || nb < -9)
	{
		len++;
		nb /= 10;
	}
	return (len + 1);
}

/**
 * Fills the given array with the digits the given integer consists of
 *
 * @param	a	The null terminated array (with at least len + 1 size) to fill
 * @param	n	The integer to fill the array with
 * @param	len	The length of the given integer
 */
static void	fill(char *a, long n, int len)
{
	long	tmp;

	while (len)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp *= -1;
		*(a + len - 1) = (char)(tmp + '0');
		n /= 10;
		len--;
	}
}

/**
 * Stores an integer in a malloced char array
 *
 * @param	n	Integer to store
 *
 * @return	A malloced array containing the integer as a string
 */
char	*ft_itoa(long n)
{
	char	*a;
	int		len;
	int		negative;

	negative = 0;
	if (n < 0)
		negative = 1;
	len = long_len(n);
	a = malloc((negative + len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	ft_memset(a, 0, negative + len + 1);
	if (negative)
	{
		*a = '-';
		fill(a + 1, n, len);
	}
	else
		fill(a, n, len);
	return (a);
}
