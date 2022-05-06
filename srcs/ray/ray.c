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

t_ray	create_ray(t_minirt_data *data, int i, int j)
{
	t_ray	ray;
	t_xyz	lower;
	double	u;
	double	v;

	u = (double) i / (data->mlx->width - 1);
	v = (double) j / (data->mlx->height - 1);
	ray.origin = data->camera.coords;
	lower = minus(data->camera.coords, init_coords(data->mlx->width, 0, 0));
	lower = minus(lower, init_coords(0, data->mlx->height, 0));
	lower = minus(lower, init_coords(0, 0, 1.0));
	ray.direction = plus(lower, mult_xyz_dub(
				init_coords(data->mlx->width, 0, 0), u));
	ray.direction = plus(ray.direction, mult_xyz_dub(
				init_coords(0, data->mlx->height, 0), v));
	ray.direction = minus(ray.direction, data->camera.coords);
	return (ray);
}
