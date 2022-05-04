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

t_bool	ratio_range(double min, double max, double value)
{
	if (value < min || value > max)
		return (false);
	return (true);
}

void	parse_a(char **arr, int len, char *line, t_minirt_data *data)
{
	t_bool	success;
	char	**ambient;

	if (len != 3)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	success = false;
	data->ambient.ratio = ft_atod((const char *)arr[1], &success);
	if (success == false || range(0, 1, data->ambient.ratio) == false)
		err_exit(1, "Error\nOut of range\n");
	ambient = split_helper(arr[2], 3);
	set_colors(&data->ambient.rgb, ambient);
	free(line);
	free_array(arr);
}

void	parse_c(char **arr, int len, char *line, t_minirt_data *data)
{
	char	**coords;
	char	**vector;
	char	**views;

	free(arr[0]);
	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	coords = ft_split(arr[1], func);
	vector = ft_split(arr[2], func);
	views = ft_split(arr[3], func);
	if (!is_valid(coords, vector, views))
		err_exit(1, "Error\nOut of range\n");
	set_coords(&data->camera.coords, coords);
	set_vector(&data->camera.vector, vector);
	set_view(&data->camera, views[0]);
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
	if (ratio_range(0, 1, data->light.ratio) == false)
		err_exit(1, "Error\nOut of range.\n");
	colors = split_helper(arr[3], 3);
	set_coords(&data->light.xyz, coords);
	set_colors(&data->light.rgb, colors);
	free_array(arr);
	free(line);
}
