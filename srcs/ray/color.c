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
#include "ray.h"
#include <math.h>
#include <printf.h>
#include "../vectorlib/vector.h"

int	get_color(t_rgb rgb, t_minirt_data *data) //TODO create ambient if it doesn't exist
{
	int	color;

	color = (int)(rgb.t_s_rgb.r * ((data->ambient.rgb.t_s_rgb.r * 255)
				* data->ambient.ratio));
	color = (color << 8) + (int)(rgb.t_s_rgb.g
			* ((data->ambient.rgb.t_s_rgb.g * 255) * data->ambient.ratio));
	color = (color << 8) + (int)(rgb.t_s_rgb.b
			* ((data->ambient.rgb.t_s_rgb.b * 255) * data->ambient.ratio));
	color = (color << 8) + 255;
	return (color);
}

double	g_m(double light, double ambient, double light_distance,
	t_minirt_data *data, double angle)
{
	double	color;
	double	light_ratio;

	light_ratio = data->light.ratio - (light_distance / 50) - (angle * 0.15);
	if (light_ratio < 0)
		light_ratio = 0;
	color = ((light * 255 * light_ratio)
			+ (ambient * 255 * data->ambient.ratio));
	if (color > 255)
		return (255);
	return (color);
}

int	get_color_with_light(t_obj_data *obj, t_minirt_data *data, double light_distance)
{
	int		color;
	t_rgb	rgb;

	rgb = obj->color;
	color = (int)(rgb.t_s_rgb.r * g_m(
				data->light.rgb.rgb[0], data->ambient.rgb.rgb[0],
				light_distance, data, obj->angle));
	color = (color << 8) + (int)(rgb.t_s_rgb.g * g_m(
				data->light.rgb.rgb[1], data->ambient.rgb.rgb[1],
				light_distance, data, obj->angle));
	color = (color << 8) + (int)(rgb.t_s_rgb.b * g_m(
				data->light.rgb.rgb[2], data->ambient.rgb.rgb[2],
				light_distance, data, obj->angle));
	color = (color << 8) + 255;
	return (color);
}

static t_rgb	init_color(double r, double g, double b)
{
	t_rgb	rgb;

	rgb.t_s_rgb.r = r;
	rgb.t_s_rgb.g = g;
	rgb.t_s_rgb.b = b;
	return (rgb);
}

t_rgb	color_mult_dub(double pixel, t_rgb a)
{
	t_rgb	rgb;

	rgb.t_s_rgb.r = fmin(a.t_s_rgb.r * pixel, 1.0);
	rgb.t_s_rgb.g = fmin(a.t_s_rgb.g * pixel, 1.0);
	rgb.t_s_rgb.b = fmin(a.t_s_rgb.b * pixel, 1.0);
	if (rgb.t_s_rgb.r < 0)
		rgb.t_s_rgb.r = 1;
	if (rgb.t_s_rgb.g < 0)
		rgb.t_s_rgb.g = 1;
	if (rgb.t_s_rgb.b < 0)
		rgb.t_s_rgb.b = 1;
	return (rgb);
}

t_rgb	color_add(t_rgb a, t_rgb b)
{
	t_rgb	rgb;

	rgb.t_s_rgb.r = fmin(a.t_s_rgb.r + b.t_s_rgb.r, 1.0);
	rgb.t_s_rgb.g = fmin(a.t_s_rgb.g + b.t_s_rgb.g, 1.0);
	rgb.t_s_rgb.b = fmin(a.t_s_rgb.b + b.t_s_rgb.b, 1.0);
	return (rgb);
}

double	hit_plane(t_xyz xyz, t_xyz vector, t_ray ray)
{
	double	d;

	d = dot(vector, ray.direction);
	if (fabs(d) > 0.0001)
		return (dot((minus(xyz, ray.origin)), vector) / d);
	return (INFINITY);
}

t_bool	hit_sphere(t_sphere *sphere, double radius, t_ray ray)
{
	t_xyz	oc;
	double	a;
	double	b;
	double	c;

	oc = minus(sphere->xyz, ray.origin);
	a = dot(oc, ray.direction);
	if (a < 0)
		return (FALSE);
	b = dot(oc, oc) - a * a;
	if (b > radius * radius)
		return (FALSE);
	c = sqrt(radius * radius - b);
	sphere->distance1 = a - c;
	sphere->distance2 = a + c;
	return (TRUE);
}

double	distance(t_xyz one, t_xyz two)
{
	t_xyz	res;

	res = minus(one, two);
	return (length(res));
}

void	loop_sphere(t_ray ray, t_list *entry, t_obj_data *obj)
{
	t_sphere	*sphere;

	while (entry)
	{
		sphere = entry->content;
		if (!hit_sphere(sphere, sphere->diameter / 2.0, ray))
		{
			entry = entry->next;
			continue ;
		}
		if (sphere->distance1 < 0)
			sphere->distance1 = sphere->distance2;
		if (sphere->distance1 < obj->distance)
		{
			obj->color = sphere->rgb;
			obj->has_color = TRUE;
			obj->distance = sphere->distance1;
			obj->sphere = sphere;
		}
		entry = entry->next;
	}
}

void	loop_plane(t_ray ray, t_list *entry, t_obj_data *obj)
{
	t_plane	*plane;
	double	distance;

	while (entry)
	{
		plane = entry->content;
		distance = hit_plane(plane->xyz, plane->vector, ray);
		if (distance < obj->distance && distance > 0)
		{
			obj->color = plane->rgb;
			obj->has_color = TRUE;
			obj->distance = distance;
			obj->plane = plane;
		}
		entry = entry->next;
	}
}

void	loop_objects(t_ray ray, t_minirt_data *data, t_obj_data *obj)
{
	obj->distance = INFINITY;
	obj->has_color = FALSE;
	loop_sphere(ray, data->sphere_list, obj);
	loop_plane(ray, data->plane_list, obj);
}

int	tem(t_minirt_data *data, t_obj_data *obj, t_ray old_ray)
{
	t_ray		ray;
	t_obj_data	new_obj;
	double		light_distance;
	t_xyz		tmp_vector;

	ray.origin = plus(mult_xyz_dub(old_ray.direction, obj->distance - 0.001), old_ray.origin);
	light_distance = distance(ray.origin, data->light.xyz);
	ray.direction = normalized(minus(data->light.xyz, ray.origin));
	loop_objects(ray, data, &new_obj);
	if (new_obj.distance < light_distance)
		return (get_color(obj->color, data));
	if (obj->sphere != NULL)
	{
		tmp_vector = normalized(minus(ray.origin, obj->sphere->xyz));
		obj->angle = acos(dot(ray.direction, tmp_vector) / (magnitute(ray.direction) * magnitute(tmp_vector)));
		if (obj->angle < 0)
			obj->angle *= -1;
	}
	return (get_color_with_light(obj, data, light_distance));
}

int	ray_color(t_ray ray, t_minirt_data *data)
{
	t_rgb		rgb;
	t_rgb		tmp;
	t_xyz		xyz;
	double		t;
	t_obj_data	obj;

	ft_bzero(&obj, sizeof(t_obj_data));
	loop_objects(ray, data, &obj);
	if (obj.has_color == TRUE)
		return (tem(data, &obj, ray));
	xyz = unit_vector(ray.direction);
	t = 0.5 * (xyz.t_s_xyz.y + 1.0);
	rgb = color_mult_dub(1.0 - t, init_color(1.0, 1.0, 1.0));
	tmp = color_mult_dub(t, init_color(0.5, 0.7, 1.0));
	return (get_color(color_add(rgb, tmp), data));
}
