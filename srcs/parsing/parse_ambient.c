/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ambient.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 10:53:29 by abba          #+#    #+#                 */
/*   Updated: 2022/06/20 10:53:29 by abba          ########   odam.nl         */
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
	success = FALSE;
	data->ambient.ratio = ft_atod((const char *)arr[1], &success);
	if (success == FALSE || range(0, 1, data->ambient.ratio) == FALSE)
		err_exit(1, "Error\nA out of range [%s].\n", line);
	ambient = split_helper((const char **)arr, 2, 3);
	set_colors(&data->ambient.rgb, ambient);
	free_array(arr);
}
