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

static double	convert_to_after_dot(double d)
{
	while (d > 1)
		d /= 10;
	return (d);
}

static double	return_result(double res1, double res2, int negative)
{
	if (res1 == 0 && negative)
		return ((res1 + res2) * -1);
	else if (res1 >= 0)
		return (res1 + res2);
	return (res1 - res2);
}

static double	convert_part_two(const char *str, t_bool *success,
					double res1, int negative)
{
	double	res2;

	if (*str != '.')
	{
		*success = TRUE;
		return (res1);
	}
	else if (!ft_isalnum(*(++str)))
	{
		*success = FALSE;
		return (0);
	}
	res2 = ft_atoi(str, success);
	if (*success == FALSE)
		return (0);
	*success = TRUE;
	return (return_result(res1, convert_to_after_dot(res2), negative));
}

double	ft_atod(const char *str, t_bool *success)
{
	double	res1;
	int		negative;

	if (!str)
		return (0);
	while (ft_iswhite_space(*str))
		str++;
	negative = 0;
	if (*str == '-')
		negative = 1;
	res1 = ft_atoi(str, success);
	if (*success == FALSE)
		return (0);
	while (ft_isdigit(*str))
		str++;
	return (convert_part_two(str, success, res1, negative));
}
