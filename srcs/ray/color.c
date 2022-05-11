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
#include "../vectorlib/vector.h"

int	get_color(t_rgb rgb)
{
	int	color;

	color = (int)(rgb.t_s_rgb.r * 255);
	color = (color << 8) + (int)(rgb.t_s_rgb.g * 255);
	color = (color << 8) + (int)(rgb.t_s_rgb.b * 255);
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
	return (-1);
}

double	hit_sphere(t_xyz xyz, double radius, t_ray ray)
{
	t_xyz	oc;
	double	a;
	double	b;
	double	c;
	double	d;

	oc = minus(ray.origin, xyz);
	a = dot(ray.direction, ray.direction);
	b = 2.0 * dot(oc, ray.direction);
	c = dot(oc, oc) - radius * radius;
	d = (b * b) - (4 * c * a);
	return (d);
}

int	loop_sphere(t_ray ray, t_list *entry)
{
	t_sphere	*sphere;
	double		distance;
	double		old_distance;
	int			clr;

	clr = -1;
	old_distance = -1;
	while (entry)
	{
		sphere = entry->content;
		distance = hit_sphere(sphere->xyz, sphere->diameter / 2.0, ray);
		if ((old_distance == -1 && distance > 0)
			|| (old_distance < distance && distance > 0)) //TODO this first < is supposed to be > but the ray seems to check the back of the circle
		{
			clr = get_color(sphere->rgb);
			old_distance = distance;
		}
		entry = entry->next;
	}
	return (clr);
}

int	loop_plane(t_ray ray, t_list *entry)
{
	t_plane	*plane;
	double	distance;
	double	old_distance;
	int		clr;

	clr = -1;
	old_distance = -1;
	while (entry)
	{
		plane = entry->content;
		distance = hit_plane(plane->xyz, plane->vector, ray);
		if ((old_distance == -1 && distance > 0)
			|| (old_distance > distance && distance > 0))
		{
			clr = get_color(plane->rgb);
			old_distance = distance;
		}
		entry = entry->next;
	}
	return (clr);
}

int	ray_color(t_ray ray, t_minirt_data *data)
{
	t_rgb		rgb;
	t_rgb		final;
	t_rgb		tmp;
	t_xyz		xyz;
	double		t;
	int			clr;

//	clr = loop_sphere(ray, data->sphere_list);
//	if (clr != -1)
//		return (clr);
	clr = loop_plane(ray, data->plane_list);
	if (clr != -1)
		return (clr);
	xyz = unit_vector(ray.direction);
	t = 0.5 * (xyz.t_s_xyz.y + 1.0);
	rgb = color_mult_dub( 1.0 - t, init_color(1.0, 1.0, 1.0));
	tmp = color_mult_dub(t, init_color(0.5, 0.7, 1.0));
	final = color_add(rgb, tmp);
	return (get_color(final));
}
