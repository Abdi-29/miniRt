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

t_bool	set_vector(t_xyz *xyz, const char **coords)
{
	int			i;
	t_bool		success;

	i = 0;
	while (i < 3)
	{
		xyz->xyz[i] = ft_atod(coords[i], &success);
		if (success == false)
			err_exit(1, "Error\nInvalid double [%s].\n", coords[i]);
		if (range(-1, 1, xyz->xyz[i]) == false)
			err_exit(1, "Error\nInvalid range for double [%s].\n", coords[i]);
		i++;
	}
	return (true);
}
