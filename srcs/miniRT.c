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

int	main(int len, char **args)
{
	t_minirt_data	data;

	if (len != 2)
		err_exit(1, "Error\nInvalid argument length, expecting file name.\n");
	data.cylinder_list = NULL;
	data.plane_list = NULL;
	data.sphere_list = NULL;
	parse_file(args[1], &data);
	start_window(&data);
	return (0);
}
