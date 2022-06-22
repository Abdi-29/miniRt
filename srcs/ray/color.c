/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 19:24:08 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/06 19:24:08 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rgb.h"
#include "../../includes/ray.h"
#include <math.h>
#include "../../includes/vector.h"

static t_rgb	init_color(double r, double g, double b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_rgb	color_mult_dub(double pixel, t_rgb a)
{
	t_rgb	rgb;

	rgb.r = fmin(a.r * pixel, 1.0);
	rgb.g = fmin(a.g * pixel, 1.0);
	rgb.b = fmin(a.b * pixel, 1.0);
	if (rgb.r < 0)
		rgb.r = 1;
	if (rgb.g < 0)
		rgb.g = 1;
	if (rgb.b < 0)
		rgb.b = 1;
	return (rgb);
}

t_rgb	color_add(t_rgb a, t_rgb b)
{
	t_rgb	rgb;

	rgb.r = fmin(a.r + b.r, 1.0);
	rgb.g = fmin(a.g + b.g, 1.0);
	rgb.b = fmin(a.b + b.b, 1.0);
	return (rgb);
}

void	loop_objects(t_ray ray, t_minirt_data *data, t_obj_data *obj,
				t_bool light)
{
	obj->distance = INFINITY;
	obj->has_color = FALSE;
	loop_sphere(ray, data->sphere_list, obj, light);
	loop_plane(ray, data->plane_list, obj);
	loop_cylinder(ray, data->cylinder_list, obj);
}

int	ray_color(t_ray ray, t_minirt_data *data)
{
	t_rgb		rgb;
	t_rgb		tmp;
	t_vec3		xyz;
	double		t;
	t_obj_data	obj;

	ft_bzero(&obj, sizeof(t_obj_data));
	loop_objects(ray, data, &obj, FALSE);
	if (obj.has_color == TRUE)
		return (calculate_light(data, &obj, ray));
	xyz = unit_vector(ray.direction);
	t = 0.5 * (xyz.y + 1.0);
	rgb = color_mult_dub(1.0 - t, init_color(1.0, 1.0, 1.0));
	tmp = color_mult_dub(t, init_color(0.5, 0.7, 1.0));
	return (get_color(color_add(rgb, tmp), data));
}
