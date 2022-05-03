/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:20:48 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 15:20:48 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/xyz.h"
#include "../includes/lib.h"
#include "../includes/util.h"
#include <stdio.h>

static double	parse_coords(const char *coord, t_bool *success, t_bool has_range)
{
	double	nbr;

	nbr = ft_atod(coord, success);
	if (has_range)
	{
		if (range(-1, 1, nbr) == false)
			*success = false;
	}
	return (nbr);
}

t_bool	set_coords(t_xyz *xyz, const char **coords, t_bool has_range)
{
	t_bool		valid;
	const char	*tmp[3] = {coords[0], coords[1], coords[2]};
	int 		i;

	i = 0;
	while (i < 3)
	{
		xyz->xyz[i] = parse_coords(tmp[i], &valid, has_range);
		if (valid == false)
			err_exit(1, "Error\nOut of range\n");
		i++;
	}
	return (true);
}
