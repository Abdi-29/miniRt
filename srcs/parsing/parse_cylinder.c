/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 12:32:15 by abba          #+#    #+#                 */
/*   Updated: 2022/06/20 12:32:15 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"
#include "../../includes/vector.h"

static int	get_value(char *str)
{
	t_bool	success;
	double	value;

	value = ft_atod(str, &success);
	if (!success)
		err_exit(1, "Error\nInvalid double [%s].\n", str);
	return (value);
}

void	parse_cylinder(char **arr, int len, char *line, t_minirt_data *data)
{
	t_cylinder	*cylinder;
	t_list		*entry;
	t_element	element;

	if (len != 6)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (cylinder == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	entry = ft_lstnew(cylinder);
	if (entry == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	ft_lstadd_back(&data->cylinder_list, entry);
	element.coords = split_helper((const char **)arr, 1, 3);
	element.vector = split_helper((const char **)arr, 2, 3);
	element.rgb = split_helper((const char **)arr, 5, 3);
	set_coords(&cylinder->origin, element.coords);
	set_vector(&cylinder->direction, element.vector);
	cylinder->direction = normalized(cylinder->direction);
	set_colors(&cylinder->rgb, element.rgb);
	cylinder->diameter = get_value(arr[3]);
	cylinder->height = get_value(arr[4]);
	free_array(arr);
}
