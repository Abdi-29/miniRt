/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_plspcy.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 19:22:15 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 19:22:15 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"

void	parse_sp(char **arr, int len, char *line, t_minirt_data *data)
{
	t_sphere	*sphere;
	t_list		*entry;
	char		**coords;
	char		**rgb;
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
	coords = ft_split(arr[1], func);
	rgb = ft_split(arr[3], func);
	if (coords == NULL || arr_len((const char **) coords) != 3
		|| rgb == NULL || arr_len((const char **) rgb) != 3)
		err_exit(1, "Error\nOut of range [%s].\n", line);
	sphere->diameter = ft_atod(arr[2], &success);
	if (!success)
		err_exit(1, "Error\nInvalid double [%s].\n", arr[2]);
	set_coords(&sphere->xyz, (const char **) coords);
	set_colors(&sphere->rgb, (const char **) rgb);
	free_array(arr);
}

void	parse_pl(char **arr, int len, char *line, t_minirt_data *data)
{
	t_plane	*plane;
	t_list	*entry;
	char	**coords;
	char	**vector;
	char	**rgb;

	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	plane = ft_calloc(1, sizeof(t_plane));
	if (plane == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	entry = ft_lstnew(plane);
	if (entry == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	ft_lstadd_back(&data->sphere_list, entry);
	coords = ft_split(arr[1], func);
	vector = ft_split(arr[2], func);
	rgb = ft_split(arr[3], func);
	if (coords == NULL || arr_len((const char **) coords) != 3
		|| rgb == NULL || arr_len((const char **) rgb) != 3)
		err_exit(1, "Error\nOut of range [%s].\n", line);
	set_coords(&plane->xyz, (const char **) coords);
	set_vector(&plane->vector, (const char **) vector);
	set_colors(&plane->rgb, (const char **) rgb);
	free_array(arr);
}

void	parse_cy(char **arr, int len, char *line, t_minirt_data *data)
{
	t_cylinder	*cylinder;
	t_list		*entry;
	char		**coords;
	char		**vector;
	char		**rgb;
	t_bool		success;

	if (len != 6)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	cylinder = ft_calloc(1, sizeof(t_cylinder));
	if (cylinder == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	entry = ft_lstnew(cylinder);
	if (entry == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	ft_lstadd_back(&data->sphere_list, entry);
	coords = ft_split(arr[1], func);
	vector = ft_split(arr[2], func);
	rgb = ft_split(arr[5], func);
	if (coords == NULL || arr_len((const char **) coords) != 3
		|| rgb == NULL || arr_len((const char **) rgb) != 3)
		err_exit(1, "Error\nOut of range [%s].\n", line);
	set_coords(&cylinder->xyz, (const char **) coords);
	set_vector(&cylinder->vector, (const char **) vector);
	set_colors(&cylinder->rgb, (const char **) rgb);
	cylinder->diameter = ft_atod(arr[3], &success);
	if (!success)
		err_exit(1, "Error\nInvalid double [%s].\n", arr[3]);
	cylinder->height = ft_atod(arr[4], &success);
	if (!success)
		err_exit(1, "Error\nInvalid double [%s].\n", arr[4]);
	free_array(arr);
}
