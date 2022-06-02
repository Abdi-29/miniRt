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
#include <stdio.h>

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

//TODO what's g_m and why it's divide by 50
double	g_m(double light, double ambient, double light_distance,
	t_minirt_data *data, double angle)
{
	double	color;
	double	light_ratio;

//	angle = angle / 180;
//	light_ratio = data->light.ratio - (light_distance / 50) - (angle);
    light_ratio = angle;
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
            obj->plane = NULL;
            obj->cylinder = NULL;
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
            obj->sphere = NULL;
            obj->cylinder = NULL;
		}
		entry = entry->next;
	}
}

void get_delta(t_cylinder *cylinder, t_ray ray)
{
    t_xyz	oc;
    t_ray	new_ray;

    new_ray.origin = ray.origin;
    cylinder->vector = normalized(cylinder->vector);
    new_ray.direction = cross(ray.direction, cylinder->vector);
    oc = minus(ray.origin, cylinder->xyz);
    cylinder->delta.delta[0] = dot(new_ray.direction, new_ray.direction);
    cylinder->delta.delta[1] = 2 * dot(new_ray.direction, cross(oc, cylinder->vector));
    cylinder->delta.delta[2] = dot(cross(oc, cylinder->vector), cross(oc, cylinder->vector))
               - pow(cylinder->diameter / 2, 2);
}

t_bool  cylinder_hit_point(t_ray ray, t_cylinder *cylinder, double max)
{
    t_xyz   point;
    t_xyz   len;

    point = plus(ray.origin, mult_xyz_dub(ray.direction,
             cylinder->delta.t_s_rgb.discriminant));
    len = minus(point, cylinder->xyz);
    if (length(len) <= max)
    {
        cylinder->distance1 = length(len);
        return (TRUE);
    }
    return (FALSE);
}

t_bool	cylinder_intersect(t_cylinder *cylinder, t_ray ray)
{
    double	t[2];
    double  max;


    get_delta(cylinder, ray);
    cylinder->delta.t_s_rgb.discriminant = pow(cylinder->delta.delta[1], 2) -
            4 * cylinder->delta.delta[0] * cylinder->delta.delta[2];
    if (cylinder->delta.t_s_rgb.discriminant < 0)
        return (FALSE);
    t[0] = (-cylinder->delta.delta[1] - sqrt(cylinder->delta.t_s_rgb.discriminant)) /
            (2 * cylinder->delta.delta[0]);
    t[1] = (-cylinder->delta.delta[1] + sqrt(cylinder->delta.t_s_rgb.discriminant)) /
            (2 * cylinder->delta.delta[0]);
    cylinder->delta.t_s_rgb.discriminant = t[0];
    max = sqrt(pow(cylinder->height / 2, 2) + pow(cylinder->diameter / 2, 2));
    if (cylinder_hit_point(ray, cylinder, max))
        return (TRUE);
    cylinder->delta.t_s_rgb.discriminant = t[1];
   return (cylinder_hit_point(ray, cylinder, max));
}

void	loop_cylinder(t_ray ray, t_list *entry, t_obj_data *obj)
{
    t_cylinder	*cylinder;

    while (entry)
    {
        cylinder = entry->content;
        if (!cylinder_intersect(cylinder, ray))
        {
            entry = entry->next;
            continue ;
        }
        if (cylinder->distance1 < obj->distance && cylinder->distance1 > 0)
        {
            obj->color = cylinder->rgb;
            obj->has_color = TRUE;
            obj->distance = cylinder->distance1;
            obj->cylinder = cylinder;
            obj->plane = NULL;
            obj->sphere = NULL;
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
    loop_cylinder(ray, data->cylinder_list, obj);
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
//        obj->angle = acos(dot(ray.direction, tmp_vector)) * (180 / M_PI);
        obj->angle = fabs(dot(ray.direction, tmp_vector));
	}
	else if (obj->plane != NULL)
	{
//        obj->angle = acos(dot(ray.direction, obj->plane->vector)) * (180 / M_PI);
//        if (obj->angle > 180)
//            obj->angle = 180;
//        if (obj->angle > 90)
//            obj->angle -= 90;
        obj->angle = fabs(dot(ray.direction, obj->plane->vector));
	}
    else if(obj->cylinder != NULL)
    {
        tmp_vector = normalized(minus(ray.origin, obj->cylinder->xyz));
        double lol = dot(tmp_vector, obj->cylinder->vector);
        tmp_vector = mult_xyz_dub(obj->cylinder->vector, lol);
        tmp_vector = normalized(minus(tmp_vector, ray.origin));
        obj->angle = fabs(dot(ray.direction, tmp_vector));
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
