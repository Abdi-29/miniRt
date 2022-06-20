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

#include "../includes/vec3.h"
#include "../includes/lib.h"
#include "../includes/util.h"

t_bool	set_vector(t_vec3 *xyz, char **vectors)
{
	int			i;
	t_bool		success;

	i = 0;
	while (i < 3)
	{
		xyz->xyz[i] = ft_atod(vectors[i], &success);
		if (success == FALSE)
			err_exit(1, "Error\nInvalid double [%s].\n", vectors[i]);
		if (range(-1, 1, xyz->xyz[i]) == FALSE)
			err_exit(1, "Error\nInvalid range for double [%s].\n", vectors[i]);
		i++;
	}
    free_array(vectors);
	return (TRUE);
}
