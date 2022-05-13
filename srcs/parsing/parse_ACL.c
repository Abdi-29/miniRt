/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ACL.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 19:22:18 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 19:22:18 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"
#include "../vectorlib/vector.h"

t_bool	ratio_range(double min, double max, double value)
{
	if (value < min || value > max)
		return (FALSE);
	return (TRUE);
}

void	parse_a(char **arr, int len, char *line, t_minirt_data *data)
{
	t_bool	success;
	char	**ambient;

	if (len != 3)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	success = FALSE;
	data->ambient.ratio = ft_atod((const char *)arr[1], &success);
	if (success == FALSE || range(0, 1, data->ambient.ratio) == FALSE)
		err_exit(1, "Error\nA out of range [%s].\n", line);
	ambient = split_helper(arr[2], 3);
	set_colors(&data->ambient.rgb, (const char**)ambient);
	free(line);
	free_array(arr);
}

void	parse_c(char **arr, int len, char *line, t_minirt_data *data)
{
	char	**coords;
	char	**vector;
	char	**views;

	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	coords = ft_split(arr[1], func);
	vector = ft_split(arr[2], func);
	views = ft_split(arr[3], func);
	if (!is_valid(coords, vector, views))
		err_exit(1, "Error\nC out of range [%s].\n", line);
	set_coords(&data->camera.coords, (const char **)coords);
	set_vector(&data->camera.vector, (const char **)vector);
	set_fov(&data->camera, views[0]);
	data->camera.vector = normalized(data->camera.vector);
	mat_init_axes(&data->transform, data->camera.vector);
	free_array(coords);
	free_array(vector);
	free_array(views);
	free_array(arr);
	free(line);
}

void	parse_l(char **arr, int len, char *line, t_minirt_data *data)
{
	char	**coords;
	char	**colors;
	t_bool	success;

	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	coords = split_helper(arr[1], 3);
	data->light.ratio = ft_atod(arr[2], &success);
	if (ratio_range(0, 1, data->light.ratio) == FALSE)
		err_exit(1, "Error\nL out of range [%s].\n", line);
	colors = split_helper(arr[3], 3);
	set_coords(&data->light.xyz, (const char**)coords);
	set_colors(&data->light.rgb, (const char**)colors);
	free_array(arr);
	free(line);
}
