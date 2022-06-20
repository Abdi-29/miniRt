/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   miniRt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/28 18:20:28 by abba          #+#    #+#                 */
/*   Updated: 2022/04/28 18:20:28 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void	set_default(t_minirt_data *data)
{
	data->cylinder_list = NULL;
	data->plane_list = NULL;
	data->sphere_list = NULL;
	data->ambient.loaded = FALSE;
	data->camera.loaded = FALSE;
	data->light.loaded = FALSE;
	data->ambient.ratio = 0;
	data->ambient.rgb = (t_rgb){{0, 0, 0}};
}

int	main(int len, char **args)
{
	t_minirt_data	data;

	if (len != 2)
		err_exit(1, "Error\nInvalid argument length, expecting file name.\n");
	set_default(&data);
	parse_file(args[1], &data);
	if (data.camera.loaded == FALSE)
		err_exit(1, "Error\nNo camera, so you can't see anything not even "
			"\black, exiting program...\n");
	start_window(&data);
	return (0);
}
