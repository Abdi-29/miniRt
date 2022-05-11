/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 19:20:46 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/06 19:20:46 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "../vectorlib/vector.h"
#include <math.h>
#include <stdio.h>

t_xyz	at(t_ray ray, double t)
{
	return (plus(ray.origin, mult_xyz_dub(ray.direction, t)));
}

t_xyz	init_coords(double x, double y, double z)
{
	t_xyz	xyz;

	xyz.t_s_xyz.x = x;
	xyz.t_s_xyz.y = y;
	xyz.t_s_xyz.z = z;
	return (xyz);
}

t_xyz	lower_left_corner(t_minirt_data *data)
{
	t_xyz	lower;
	t_xyz	tmp;
	double	viewport_height;
	double	viewport_width;

	viewport_height = 2.0;
	viewport_width = (16.0 / 9.0) * viewport_height;
	tmp = init_coords(viewport_width, 0, 0);
	lower = minus(data->camera.coords, division(init_coords(viewport_width, 0, 0), 2.0));
	lower = minus(lower, division(init_coords(0, viewport_height, 0), 2.0));
	lower = minus(lower, init_coords(0, 0, 1.0));
	return (lower);
}

t_xyz	construct_camera(t_minirt_data *data, int x, int y)
{
	t_xyz	xyz;

	xyz.t_s_xyz.x = ((x / data->mlx->width) - 0.5) * 2;
	xyz.t_s_xyz.y = ((y / data->mlx->height) - 0.5) * 2;
	xyz.t_s_xyz.x = 1;
	return (xyz);
}

t_ray	create_ray(t_minirt_data *data, int i, int j)
{
	t_ray	ray;
	double	screen_x;
	double	screen_y;
	double	pixel_camera_x;
	double	pixel_camera_y;
	double	image_ratio;

	screen_x = (double)2 * (((double)i + 0.5) / (double)data->mlx->width) - 1.;
	screen_y = (double)1. - 2. * (((double)j + 0.5) / (double)data->mlx->height);
	image_ratio = (double) data->mlx->width / (double) data->mlx->height;
	pixel_camera_x = screen_x * image_ratio * tan(data->camera.fov / 2 * M_PI / 180);
	pixel_camera_y = screen_y * tan(data->camera.fov / 2 * M_PI / 180);
	ray.direction = init_coords(pixel_camera_x, pixel_camera_y, -1);
	ray.direction = normalized(mat_mult_dir(data->transform, ray.direction));
	ray.origin = data->camera.coords;
	return (ray);
}
