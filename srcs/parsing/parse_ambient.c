/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ambient.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 21:30:48 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 21:30:48 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"

void	parse_ambient(char **arr, int len, char *line, t_minirt_data *data)
{
	t_bool	success;
	char	**ambient;

	if (len != 3)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
	if (data->ambient.loaded == TRUE)
		err_exit(1, "Error\nAlready loaded ambient, duplicated ambient on "
			"line [%s]\n", line);
	success = FALSE;
	data->ambient.ratio = ft_atod((const char *)arr[1], &success);
	if (success == FALSE || range(0, 1, data->ambient.ratio) == FALSE)
		err_exit(1, "Error\nA out of range [%s].\n", line);
	ambient = split_helper((const char **)arr, 2, 3);
	set_colors(&data->ambient.rgb, ambient);
	free_array(arr);
	data->ambient.loaded = TRUE;
}
