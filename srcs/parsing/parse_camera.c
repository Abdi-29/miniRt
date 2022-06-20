/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 11:51:01 by abba          #+#    #+#                 */
/*   Updated: 2022/06/20 11:51:01 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"
#include "../../includes/vector.h"

static t_bool	set_fov(t_camera *camera, char **fov)
{
	int		nbr;
	t_bool	success;

	nbr = ft_atoi(fov[0], &success);
	if (success == FALSE || nbr < 0 || nbr > 180)
		err_exit(1, "Error\nFOV out of range [%s]\n", fov);
	camera->fov = nbr;
	free_array(fov);
	return (TRUE);
}

void	parse_camera(char **arr, int len, char *line, t_minirt_data *data)
{
	char	**coords;
	char	**vector;
	char	**views;

	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	coords = split_helper((const char **)arr, 1, 3);
	vector = split_helper((const char **)arr, 2, 3);
	views = split_helper((const char **)arr, 3, 1);
	set_coords(&data->camera.coords, coords);
	set_vector(&data->camera.direction, vector);
	set_fov(&data->camera, views);
	data->camera.direction = normalized(data->camera.direction);
	mat_init_axes(&data->transform, data->camera.direction);
	free_array(arr);
}
