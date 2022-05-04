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
	void	*mlx_image;
	int		width;
	int		height;

	width = 1920;
	height = 1080;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		err_exit(1, "Error\nUnable to initialize mlx.\n");
	data->window = mlx_new_window(
			data->mlx,
			width,
			height,
			"miniRT");
	if (!data->window)
		err_exit(1, "Error\nUnable to initialize mlx window.\n");
	mlx_image = mlx_png_file_to_image(&data->mlx, "~/Desktop/C/miniRT/images/gray_background.png", &width, &height);
	if (!mlx_image)
		err_exit(1, "Error\nUnable to load background.\n");
	mlx_put_image_to_window(data->mlx, data->window, mlx_image, 0, 0);
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
