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

	color = ((color1 * rad1) + (color2 * rad2)) / 2 * 255;
	if (color > 255)
		return (255);
	return (color);
}

int	get_color_with_light(t_rgb rgb, t_minirt_data *data) //TODO create ambient if it doesn't exist
{
//	int		color;
//	double	r1;
//	double	r2;
//	double	*clr1;
//	double	*clr2;
//
//	r1 = data->ambient.ratio;
//	r2 = data->light.ratio;
//	clr1 = data->ambient.rgb.rgb;
//	clr2 = data->light.rgb.rgb;
//	color = (int)(rgb.t_s_rgb.r * g_m(clr1[0], r1, clr2[0], r2));
//	color = (color << 8) + (int)(rgb.t_s_rgb.g * g_m(clr1[1], r1, clr2[1], r2));
//	color = (color << 8) + (int)(rgb.t_s_rgb.b * g_m(clr1[2], r1, clr2[2], r2));
//	color = (color << 8) + 255;
//	return (color);
    int	color;

    color = (int)(rgb.t_s_rgb.r * ((data->light.rgb.t_s_rgb.r * 255)
                                   * data->light.ratio));
    color = (color << 8) + (int)(rgb.t_s_rgb.g
                                 * ((data->light.rgb.t_s_rgb.g * 255) * data->light.ratio));
    color = (color << 8) + (int)(rgb.t_s_rgb.b
                                 * ((data->light.rgb.t_s_rgb.b * 255) * data->light.ratio));
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

t_bool	cylinder_intersect(t_cylinder *cylinder, t_ray ray)
{
    t_xyz   oc;
    double  delta[3];
    t_ray   new_ray;
    double  tmp;
    double  t[2];

    new_ray.origin = ray.origin;
    cylinder->vector = normalized(cylinder->vector);
    new_ray.direction = cross(ray.direction, cylinder->vector);
    oc = minus(ray.origin, cylinder->xyz);
    delta[0] = dot(new_ray.direction, new_ray.direction);
    delta[1] = 2 * dot(new_ray.direction, cross(oc, cylinder->vector));
    delta[2] = dot(cross(oc, cylinder->vector), cross(oc, cylinder->vector))
               - pow(cylinder->diameter / 2, 2);
    tmp = pow(delta[1], 2) - 4 * delta[0] * delta[2];
    if (tmp < 0)
        return (FALSE);
    t[0] = (-delta[1] - sqrt(tmp)) / (2 * delta[0]);
    t[1] = (-delta[1] + sqrt(tmp)) / (2 * delta[0]);
//    if (t[1] < 0)
//        return (FALSE);
    tmp = t[0];
    t_xyz point = plus(ray.origin, mult_xyz_dub(ray.direction, tmp));
    double max = sqrt(pow(cylinder->height / 2, 2)) + sqrt(pow(cylinder->diameter / 2, 2));
    t_xyz len = minus(point, cylinder->xyz);
    if (length(len) <= max)
    {
        cylinder->distance1 = length(len);
        return (TRUE);
    }
    tmp = t[1];
    point =  plus(ray.origin, mult_xyz_dub(ray.direction, tmp));
    len = minus(point, cylinder->xyz);
    if (length(len) <= max)
    {
        cylinder->distance1 = length(len);
        return (TRUE);
    }

    return (FALSE);
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
        }
        entry = entry->next;
    }
}

//create function that ignore the object that are already hit

void	loop_objects(t_ray ray, t_minirt_data *data, t_obj_data *obj)
{
	obj->distance = INFINITY;
	obj->has_color = FALSE;
	loop_sphere(ray, data->sphere_list, obj);
	loop_plane(ray, data->plane_list, obj);
	loop_cylinder(ray, data->cylinder_list, obj);
}

/*
 * initial_points = mult_xyz_dub(ray.direction, obj->distance);
	initial_points = normalized(plus(initial_points, ray.origin));
	ray.direction = initial_points;
 */

int	tem(t_minirt_data *data, t_obj_data *obj, t_ray old_ray)
{
	t_ray		ray;
	t_obj_data	new_obj;
	double		light_distance;

	ray.origin = plus(mult_xyz_dub(old_ray.direction, obj->distance - 0.001), old_ray.origin);
	light_distance = distance(ray.origin, data->light.xyz);
	ray.direction = normalized(minus(data->light.xyz, ray.origin));
	loop_objects(ray, data, &new_obj);
//    printf("ray origin: (%f, %f, %f), ray direction: (%f, %f, %f)\n",
//           ray.origin.xyz[0], ray.origin.xyz[1], ray.origin.xyz[2],
//           ray.direction.xyz[0], ray.direction.xyz[1], ray.direction.xyz[2]);
	if (new_obj.distance < light_distance)
        return (get_color(obj->color, data));
    return (get_color_with_light(obj->color, data));
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
		return (tem(data, &obj, ray));
	xyz = unit_vector(ray.direction);
	t = 0.5 * (xyz.t_s_xyz.y + 1.0);
	rgb = color_mult_dub(1.0 - t, init_color(1.0, 1.0, 1.0));
	tmp = color_mult_dub(t, init_color(0.5, 0.7, 1.0));
	return (0x000000FF);
}
