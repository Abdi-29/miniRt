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

double	g_m(double color1, double rad1, double color2, double rad2)
{
	double	color;

	color = ((color1 * rad1) + (color2 * rad2));
	if (color > 255)
		return (255);
	return (color);
}

int	get_color_with_light(t_rgb rgb, t_minirt_data *data) //TODO create ambient if it doesn't exist
{
	int		color;
	double	r1;
	double	r2;
	double	*clr1;
	double	*clr2;

	r1 = data->ambient.ratio;
	r2 = data->light.ratio;
	clr1 = data->ambient.rgb.rgb;
	clr2 = data->light.rgb.rgb;
	color = (int)(rgb.t_s_rgb.r * g_m(clr1[0], r1, clr2[0], r2));
	color = (color << 8) + (int)(rgb.t_s_rgb.r * g_m(clr1[1], r1, clr2[1], r2));
	color = (color << 8) + (int)(rgb.t_s_rgb.r * g_m(clr1[2], r1, clr2[2], r2));
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
		}
		entry = entry->next;
	}
}

void	loop_objects(t_ray ray, t_minirt_data *data, t_obj_data *obj)
{
	obj->distance = INFINITY;
	obj->has_color = FALSE;
	loop_plane(ray, data->plane_list, obj);
	loop_sphere(ray, data->sphere_list, obj);
}

double	get_potions(double oxy, double oz, double lxy, double lz)
{
	double oxylxy;
	double ozlz;

	oxylxy = oxy - lxy;
	ozlz = oz - lz;
	double c = sqrt((oxylxy * oxylxy) + (ozlz * ozlz));
	double res = acos(oxylxy / c);
	if (res > 180)
		return (res - 180) / 180;
	return (res / 180);
}

int	tem(t_minirt_data *data, t_obj_data *obj)
{
	t_xyz		initial_points;
	t_xyz		q;
	t_xyz		s;
	t_xyz		t;
	t_xyz		light_dir;
	t_ray		ray;
	t_obj_data	new_obj;
	double		angle;
	double		lightdistance;

	initial_points = init_coords(obj->distance, 0, 0);
	q.t_s_xyz.x = cos(data->light.xyz.t_s_xyz.y) * initial_points.t_s_xyz.x
		- sin(data->light.xyz.t_s_xyz.y) * initial_points.t_s_xyz.z;
	q.t_s_xyz.y = data->light.xyz.t_s_xyz.y;
	q.t_s_xyz.z = sin(data->light.xyz.t_s_xyz.y) * initial_points.t_s_xyz.x
		+ cos(data->light.xyz.t_s_xyz.y) * initial_points.t_s_xyz.z;
	s.t_s_xyz.x = cos(data->light.xyz.t_s_xyz.x) * q.t_s_xyz.x
		- sin(data->light.xyz.t_s_xyz.x) * q.t_s_xyz.y;
	s.t_s_xyz.y = sin(data->light.xyz.t_s_xyz.x) * q.t_s_xyz.x
		+ cos(data->light.xyz.t_s_xyz.x) * q.t_s_xyz.y;
	s.t_s_xyz.z = q.t_s_xyz.z;
	t = plus(s, ray.origin);
	ray.direction.xyz[0] = get_potions(t.xyz[0], data->light.xyz.xyz[0], t.xyz[2], data->light.xyz.xyz[2]);
	ray.direction.xyz[1] = get_potions(t.xyz[1], data->light.xyz.xyz[1], t.xyz[2], data->light.xyz.xyz[2]);
	ray.direction.xyz[2] = 1;
	lightdistance = dot(ray.direction, ray.direction);
	loop_objects(ray, data, &new_obj);
	if (obj->distance < lightdistance)
		return (get_color_with_light(new_obj.color, data));
	else
		return (get_color(obj->color, data));
}

int	ray_color(t_ray ray, t_minirt_data *data)
{
	t_rgb		rgb;
	t_rgb		tmp;
	t_xyz		xyz;
	double		t;
	t_obj_data	obj;

	loop_objects(ray, data, &obj);
	if (obj.has_color == TRUE)
		return (tem(data, &obj));
	xyz = unit_vector(ray.direction);
	t = 0.5 * (xyz.t_s_xyz.y + 1.0);
	rgb = color_mult_dub(1.0 - t, init_color(1.0, 1.0, 1.0));
	tmp = color_mult_dub(t, init_color(0.5, 0.7, 1.0));
	return (get_color(color_add(rgb, tmp), data));
}
