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
	char **coords;
	char **colours;
	char *diameter;

	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	coords = split_helper(arr[1], 3);
	diameter = split_helper(arr[2], 1);
	colours = split_helper(arr[3], 3);
//	set_coords(&data->plane_list->, (const char **)coords, false);
//	set_colors(&data->light.rgb, (const char **)colours);
}

void	parse_pl(char **arr, int len, char *line, t_minirt_data *data)
{
	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
}

void	parse_cy(char **arr, int len, char *line, t_minirt_data *data)
{
	if (len != 6)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
}