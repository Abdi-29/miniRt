/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 17:59:41 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 17:59:41 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"
#include <stdio.h>

int	func(char c)
{
	if (c == ',')
		return (1);
	return (0);
}

int	arr_len(const char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	err_exit(int status, const char *str, ...)
{
	va_list	ap;

	if (str != NULL)
	{
		va_start(ap, str);
		if (status != 0)
			ft_printf_va(2, str, ap);
		else
			ft_printf_va(1, str, ap);
	}
	exit(status);
}

char	**split_helper(const char **str, int pos, int len)
{
	char	**output;

	output = ft_split(str[pos], func);
	if (output == NULL || arr_len((const char **)output) != len)
		err_exit(1, "Error\nSplit out of range [%s]\n", str[pos]);
	return (output);
}

t_bool	range(double a, double b, double value)
{
	if (value < a || value > b)
		return (FALSE);
	return (TRUE);
}
