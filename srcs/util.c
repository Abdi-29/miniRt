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

t_bool	is_valid(char **coordinates, char **vector, char **views)
{
	if (!coordinates)
		return (false);
	if (!vector)
	{
		free_array(coordinates);
		return (false);
	}
	if (!views)
	{
		free_array(coordinates);
		free_array(vector);
		return (false);
	}
	if (arr_len((const char **)vector) != 3 || arr_len((const char **)coordinates) != 3
		|| arr_len((const char **)views) != 1)
	{
		free_array(vector);
		free_array(coordinates);
		free_array(views);
		return (false);
	}
	return (true);
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

char	**split_helper(char *str, int len)
{
	char	**output;

	output = ft_split(str, func);
	if (output == NULL || arr_len((const char **)output) != len)
		err_exit(1, "Error\nSplit out of range [%s]\n", str);
	return (output);
}

t_bool	range(double a, double b, double value)
{
	if (value < a || value > b)
		return (false);
	return (true);
}
