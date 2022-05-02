/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 21:30:48 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 21:30:48 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	len_array(char **array)
{
	int	len;

	len = 0;
	while (array[len])
	{
		len++;
	}
	return (len);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

double get_left_part(const char *str, t_bool *success)
{
	double	res;
	int		len;

	len = 0;
	res = (double)ft_atoi(str, success);
	len = ft_strlen(str);
	while (len--)
		res /= 10;
	return (res);
}

double	ft_atod(const char *str, t_bool *success)
{
	double	res;
	double	res2;
	char	**test;

	res2 = 0;
	if (!str)
		return (0);
	test = ft_split(str, '.');
	if (len_array(test) > 2)
	{
		free_array(test);
		return (0);
	}
	res = ft_atoi(test[0], success);
	if (test[1])
		res2 = get_left_part(test[1], success);
	free_array(test);
	*success = true;
	if (res >= 0)
		return (res + res2);
	return (res - res2);
}
