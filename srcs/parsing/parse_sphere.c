/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 13:30:21 by abba          #+#    #+#                 */
/*   Updated: 2022/06/20 13:30:21 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"

void	parse_sphere(char **arr, int len, char *line, t_minirt_data *data)
{
	t_sphere	*sphere;
	t_list		*entry;
	t_element	element;
	t_bool		success;

	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	sphere = ft_calloc(1, sizeof(t_sphere));
	if (sphere == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	entry = ft_lstnew(sphere);
	if (entry == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	ft_lstadd_back(&data->sphere_list, entry);
	element.coords = split_helper((const char **)arr, 1, 3);
	element.rgb = split_helper((const char **)arr, 3, 3);
	sphere->diameter = ft_atod(arr[2], &success);
	if (!success)
		err_exit(1, "Error\nInvalid double [%s].\n", arr[2]);
	set_coords(&sphere->origin, element.coords);
	set_colors(&sphere->rgb, element.rgb);
	free_array(arr);
}
