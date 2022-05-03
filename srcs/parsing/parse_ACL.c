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
#include <stdio.h>

int	func(char c);

void	parse_a(char **arr, int len, char *line, t_minirt_data *data)
{
	//change set_colors function so it can work with other function
	t_bool	success;
	char **ambient;

	if (len != 3)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	data->ambient.ratio = ft_atod(arr[1], &success);
	if (success == false || range(0, 1, data->ambient.ratio) == false)
		err_exit(1, "Error\nOut of range\n");
	ambient = ft_split(arr[2], func);
	if (ambient == NULL || arr_len((const char **)ambient) != 3)
		err_exit(1, "Error\nOut of range\n");
	set_colors(&data->ambient.rgb, ambient[0], ambient[1], ambient[2]);
}

void	parse_c(char **arr, int len, char *line, t_minirt_data *data)
{
	t_bool	success;
	char 	**coords;
	char 	**vector;
	char 	**views;

	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	coords = ft_split(arr[1], func);
	vector = ft_split(arr[2], func);
	views = ft_split(arr[3], func);
	if (!is_valid(coords, vector, views))
		err_exit(1, "Error\nOut of range\n");
	//create a helper function that do all of this
	set_coords(&data->camera.coords, (const char **)coords, false);
	set_coords(&data->camera.vector, (const char **)vector, true);
	set_view(&data->camera, views[0]);
	free_array(coords);
	free_array(vector);
	free_array(views);
}

void	parse_l(char **arr, int len, char *line, t_minirt_data *data)
{
	char 	**coords;
	t_bool success;

	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	ft_printf(1, "new challenge\n");
	coords = ft_split(arr[1], func);
	//edit is_valid function so it can work with single argument
	if (!coords)
		err_exit(1, "Error\nRan out of memory.\n");
	ft_printf(1, "checking %d\n", len_array(coords));
	if (len_array(coords) != 3)
		err_exit(1, "Error1\nOut of range\n");
	set_coords(&data->light.xyz, (const char **)coords, false);
	data->light.ratio = ft_atod(coords[1], &success);
}
