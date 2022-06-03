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

#include "../../includes/ray.h"
#include "../../includes/vector.h"
#include <math.h>

t_xyz	init_coords(double x, double y, double z)
{
	t_xyz	xyz;

	xyz.t_s_xyz.x = x;
	xyz.t_s_xyz.y = y;
	xyz.t_s_xyz.z = z;
	return (xyz);
}

t_ray	create_ray(t_minirt_data *data, int i, int j)
{
	t_ray		ray;
	t_screen	sc;

	sc.screen_x = (double)2 * (((double)i + 0.5)
			/ (double)data->mlx->width) - 1.;
	sc.screen_y = (double)1. - 2. * (((double)j + 0.5)
			/ (double)data->mlx->height);
	sc.image_ratio = (double) data->mlx->width / (double) data->mlx->height;
	sc.pixel_camera_x = sc.screen_x * sc.image_ratio * tan(data->camera.fov
			/ 2. * M_PI / 180);
	sc.pixel_camera_y = sc.screen_y * tan(data->camera.fov / 2. * M_PI / 180);
	ray.direction = init_coords(sc.pixel_camera_x, sc.pixel_camera_y, 1);
	ray.direction = normalized(mat_mult_dir(data->transform, ray.direction));
	ray.origin = data->camera.coords;
	return (ray);
}
