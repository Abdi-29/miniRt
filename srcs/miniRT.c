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
#include <math.h>
#include "ray/ray.h"

typedef struct tmp
{
	int	x;
	int	y;
}	t_tmp;

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

void	empty(t_rgb *rgb, t_xyz *xyz)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		rgb->rgb[i] = -1;
		xyz->xyz[i] = -1;
		i++;
	}
}

void	draw_stuff(t_minirt_data *data)
{
	mlx_image_t	*image;
	t_tmp		tmp;
	t_ray		ray;

	image = mlx_new_image(data->mlx, data->mlx->width,
			data->mlx->height);
	tmp.x = 0;
	tmp.y = 0;
//	data->camera.lower = lower_left_corner(data);
	while (tmp.x < data->mlx->width)
	{
		while (tmp.y < data->mlx->height)
		{
			ray = create_ray(data, tmp.x, tmp.y);
			mlx_put_pixel(image, tmp.x, tmp.y, ray_color(ray, data));
			tmp.y++;
		}
		tmp.y = 0;
		tmp.x++;
	}
	mlx_image_to_window(data->mlx, image, 0, 0);
}

void	start_window(t_minirt_data *data)
{
	t_list	*entry;

	data->mlx = mlx_init(1280,
			720,
			"miniRT",
			TRUE);
	if (!data->mlx)
		err_exit(1, "Error\nUnable to initialize mlx window.\n");
	setup_listeners(data);
	draw_stuff(data);
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
