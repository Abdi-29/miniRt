/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 18:43:29 by abba          #+#    #+#                 */
/*   Updated: 2022/06/03 18:43:29 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"
#include "../includes/ray.h"

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
	(void)ptr;
	if (keycode.key == MLX_KEY_ESCAPE && keycode.action == MLX_PRESS)
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
	(void)param;
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

void	draw_stuff(t_minirt_data *data)
{
	mlx_image_t	*image;
	t_ray		ray;
	int			x;
	int			y;

	image = mlx_new_image(data->mlx, data->mlx->width,
			data->mlx->height);
	x = 0;
	y = 0;
	while (x < data->mlx->width)
	{
		while (y < data->mlx->height)
		{
			ray = create_ray(data, x, y);
			mlx_put_pixel(image, x, y, ray_color(ray, data));
			y++;
		}
		y = 0;
		x++;
	}
	mlx_image_to_window(data->mlx, image, 0, 0);
}

void	start_window(t_minirt_data *data)
{
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