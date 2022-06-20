/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 11:53:39 by abba          #+#    #+#                 */
/*   Updated: 2022/06/20 11:53:39 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"

static t_bool	ratio_range(double min, double max, double value)
{
    if (value < min || value > max)
        return (FALSE);
    return (TRUE);
}

void	parse_light(char **arr, int len, char *line, t_minirt_data *data)
{
    char	**coords;
    char	**colors;
    t_bool	success;

    if (len != 4)
        err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
                 len, line);
    coords = split_helper((const char **)arr, 1, 3);
    colors = split_helper((const char **)arr, 3, 3);
    data->light.ratio = ft_atod(arr[2], &success);
    if (ratio_range(0, 1, data->light.ratio) == FALSE)
        err_exit(1, "Error\nL out of range [%s].\n", line);
    set_coords(&data->light.origin, coords);
    set_colors(&data->light.rgb, colors);
    free_array(arr);
}
