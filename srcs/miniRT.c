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

#include <unistd.h>
#include "../libft/libft.h"
#include <stdio.h>

void	test(char *str)
{
	t_bool	success;

	printf("mine: {%f success %d} actual: {%f} string: {%s}\n",
		ft_atod(str, &success),
		success,
		atof(str),
		str);
}

int	main(void)
{
	write(1, "hello\n", 6);
	test("0.0");
	test("-0.0");
	test("1.0");
	test("00000003.1");
	test("1.1");
	test("0999.809289");
	test("999999.444");
	test("666.666");
	return (0);
}
