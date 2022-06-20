/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 13:24:22 by abba          #+#    #+#                 */
/*   Updated: 2022/06/20 13:24:22 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"

void	parse_plane(char **arr, int len, char *line, t_minirt_data *data)
{
	t_plane		*plane;
	t_list		*entry;
	t_element	element;

	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	plane = ft_calloc(1, sizeof(t_plane));
	if (plane == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	entry = ft_lstnew(plane);
	if (entry == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	ft_lstadd_back(&data->plane_list, entry);
	element.coords = split_helper((const char **)arr, 1, 3);
	element.vector = split_helper((const char **)arr, 2, 3);
	element.rgb = split_helper((const char **)arr, 3, 3);
	set_coords(&plane->origin, element.coords);
	set_vector(&plane->direction, element.vector);
	set_colors(&plane->rgb, element.rgb);
	free_array(arr);
}
