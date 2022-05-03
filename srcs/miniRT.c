/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   miniRt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/28 18:20:28 by abba          #+#    #+#                 */
/*   Updated: 2022/04/28 18:20:28 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"
#include "../includes/parser.h"
#include <stdio.h>

int	main(int len, char **args)
{
	t_minirt_data	data;

	if (len != 2)
		err_exit(1, "Error\nInvalid argument length, expecting file name.\n");
	parse_file(args[1], &data);
	return (0);
}

//int	main()
//{
//	t_bool	b;
//	double	a, c;
//
//	a = ft_atod("-2147483649.37", &b);
//	c = atof("-2147483649.37");
//	printf("(%f) - %d, (%f)\n", a, b, c);
//	return (1);
//}