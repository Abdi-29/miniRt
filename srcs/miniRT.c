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

int	get_color(t_rgb rgb)
{
	int	color;

	color = rgb.t_s_rgb.r;
	color = (color << 8) + rgb.t_s_rgb.g;
	color = (color << 8) + rgb.t_s_rgb.b;
	return (color);
}

void	draw_sphere(t_sphere *sphere, t_minirt_data *data)
{
	mlx_image_t	*image;
	int			x;
	int			y;
	int			rad;

	image = mlx_new_image(data->mlx, (int) sphere->diameter,
			(int) sphere->diameter);
	rad = (int)(sphere->diameter / 2);
	x = -1 * rad;
	y = x;
	while (x <= rad)
	{
		while (y <= rad)
		{
			if ((x * x) + (y * y) < (sphere->diameter * sphere->diameter) / 4)
				mlx_put_pixel(image, x + rad, y + rad, get_color(sphere->rgb));
			y++;
		}
		y = -rad;
		x++;
	}
	ft_printf(2, "Drawing image\n");
	mlx_image_to_window(data->mlx, image, data->mlx->width / 2, data->mlx->height / 2);
}

void	draw_plane(t_plane *plane, t_minirt_data *data)
{
	mlx_image_t	*image;
	int			x;
	int			y;
}

void	start_window(t_minirt_data *data)
{
	t_list	*entry;

	data->mlx = mlx_init(1920,
			1080,
			"miniRT",
			true);
	if (!data->mlx)
		err_exit(1, "Error\nUnable to initialize mlx window.\n");
	setup_listeners(data);
	entry = data->sphere_list;
	while (entry)
	{
		draw_sphere(entry->content, data);
		entry = entry->next;
	}
	mlx_loop(data->mlx);
}

void	init_data(t_minirt_data *data)
{
	data->cylinder_list = NULL;
	data->plane_list = NULL;
	data->sphere_list = NULL;
}

int	main(int len, char **args)
{
	t_minirt_data	data;

	if (len != 2)
		err_exit(1, "Error\nInvalid argument length, expecting file name.\n");
	init_data(&data);
	parse_file(args[1], &data);
	start_window(&data);
	return (0);
}
