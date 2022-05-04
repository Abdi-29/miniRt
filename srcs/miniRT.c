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
#include "../includes/parser.h"

void	start_window(t_minirt_data *data)
{
	data->mlx.window = mlx_init(1920,
			1080,
			"miniRT",
			true);
	if (!data->mlx.window)
		err_exit(1, "Error\nUnable to initialize mlx window.\n");
//	data->bgbuffer = mlx_new_image()
//	draw_textures();
}

int	main(int len, char **args)
{
	t_minirt_data	data;

	if (len != 2)
		err_exit(1, "Error\nInvalid argument length, expecting file name.\n");
	parse_file(args[1], &data);
	start_window(&data);
	return (0);
}
