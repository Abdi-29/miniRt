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

int	dot_char(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int	is_negative(char *s)
{
	while (ft_iswhite_space(*s) && *s != 0)
		s++;
	return (*s == '-');
}

double	get_left_part(const char *str, t_bool *success)
{
	double	res;
	int		len;

	res = (double)ft_atoi(str, success);
	if (*success == FALSE)
		return (0);
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
	int		sig;

	res2 = 0;
	if (!str)
		return (0);
	test = ft_split(str, dot_char);
	if (len_array(test) > 2)
	{
		free_array(test);
		return (0);
	}
	res = ft_atoi(test[0], success);
	if (*success == FALSE)
		return (0);
	sig = is_negative(test[0]);
	if (test[1])
		res2 = get_left_part(test[1], success);
	if (*success == FALSE)
		return (0);
	free_array(test);
	*success = TRUE;
	if (res == 0 && sig)
		return ((res + res2) * -1);
	else if (res >= 0)
		return (res + res2);
	return (res - res2);
}
