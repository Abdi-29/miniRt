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

void	set_coords(t_xyz *xyz, char **coords)
{
	int			i;
	t_bool		success;

	i = 0;
	while (i < 3)
	{
		xyz->xyz[i] = ft_atod(coords[i], &success);
		if (success == false)
			err_exit(1, "Error\nInvalid double [%s].\n", coords[i]);
		i++;
	}
}
