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

/**
 * Listens for key clicks and runs functions based on those clicks
 *
 * 	exc = 53
 *
 * @param	keycode	Key code the user clicked
 * @param	ptr		Pointer to data for the game
 *
 * @return	0
 */
void	key_click(mlx_key_data_t keycode, void *ptr)
{
	t_minirt_data	*data;

	data = ptr;
	if (keycode.os_key == 53 && keycode.action == MLX_PRESS)
	{
		exit(0);
	}
}

/**
 * Listens if the game window closes and if so ends the game
 *
 * @param	param	Pointer to data for the game
 *
 * @return	0
 */
void	window_close(void *param)
{
	t_minirt_data	*data;

	data = param;
	exit(0);
}

/**
 * Start all listeners for the game
 * 	mlx_key_hook listens to any keypress
 * 	mlx_hook listens if the user closes the window with the red x
 *
 * @param	data	All game data
 */
void	setup_listeners(t_minirt_data *data)
{
	mlx_key_hook(data->mlx, key_click, data);
	mlx_close_hook(data->mlx, window_close, data);
}

void	draw_sphere(t_sphere *sphere, t_minirt_data *data)
{
	mlx_image_t	*image;

	image = mlx_new_image(data->mlx, sphere->diameter, sphere->diameter);
	int i, j, x, y;
	i = 0;
	j = 0;
	while (i < sphere->diameter)
	{
		while (j < sphere->diameter)
		{
			x = i - (sphere->diameter / 2);
			y = j - (sphere->diameter / 2);
			if ((x * x) + (y * y) < sphere->diameter / 4)
				mlx_put_pixel(image, i, j, 999);
			j++;
		}
		i++;
	}
	ft_printf(2, "Drawing image\n");
	mlx_image_to_window(data->mlx, image, 0, 0);
}

void	start_window(t_minirt_data *data)
{
	data->mlx = mlx_init(1920,
			1080,
			"miniRT",
			true);
	if (!data->mlx)
		err_exit(1, "Error\nUnable to initialize mlx window.\n");
	setup_listeners(data);
	t_list	*entry;
	entry = data->sphere_list;
	ft_printf(2, "entry: %p\n", entry);
	while (entry)
	{
		t_sphere	*sphere = entry->content;
		ft_printf(2, "drawing: %p\n", entry);
		draw_sphere(sphere, data);
		entry = entry->next;
	}
	mlx_loop(data->mlx);
}

int	main(int len, char **args)
{
	t_minirt_data	data;

	if (len != 2)
		err_exit(1, "Error\nInvalid argument length, expecting file name.\n");
	parse_file(args[1], &data);
	ft_printf(2, "hey %p\n", data.sphere_list);
	start_window(&data);
	return (0);
}
