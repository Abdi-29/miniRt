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

void	start_window(t_minirt_data *data)
{
	data->mlx = mlx_init(1920,
			1080,
			"miniRT",
			true);
	if (!data->mlx)
		err_exit(1, "Error\nUnable to initialize mlx window.\n");
	setup_listeners(data);
	mlx_loop(data->mlx);
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
