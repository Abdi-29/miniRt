/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/28 18:59:10 by abba          #+#    #+#                 */
/*   Updated: 2022/04/28 18:59:10 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(char *s, int *sign, int *neg)
{
	int	i;

	i = 0;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '+' || s[i] == '-')
		{
			*sign += 1;
			if (s[i] == '-')
				*neg *= -1;
		}
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		number;
	char	*str_copy;
	int		neg;

	str_copy = (char *)str;
	number = 0;
	sign = 0;
	neg = 1;
	str_copy = ft_whitespaces(str_copy);
	str_copy += ft_sign(str_copy, &sign, &neg);
	if (sign > 1)
	{
		return (0);
	}
	while (*str_copy)
	{
		if (!(ft_isdigit(*str_copy)))
			break ;
		number = (*str_copy - 48) + (number * 10);
		str_copy++;
	}
	return (number * neg);
}
