/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ligth.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 19:49:03 by abba          #+#    #+#                 */
/*   Updated: 2022/06/18 19:41:50 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rgb.h"
#include <math.h>
#include "../../includes/ray.h"
#include "../../includes/vector.h"

int	get_color(t_rgb rgb, t_minirt_data *data)
{
	int	color;

	color = (int)(rgb.r * ((data->ambient.rgb.r * 255)
				* data->ambient.ratio));
	color = (color << 8) + (int)(rgb.g
			* ((data->ambient.rgb.g * 255) * data->ambient.ratio));
	color = (color << 8) + (int)(rgb.b
			* ((data->ambient.rgb.b * 255) * data->ambient.ratio));
	color = (color << 8) + 255;
	return (color);
}

static int	final_color(t_rgb rgb)
{
	int	color;

	color = (int)(rgb.r * 255);
	color = (color << 8) + (int)(rgb.g * 255);
	color = (color << 8) + (int)(rgb.b * 255);
	color = (color << 8) + 255;
	return (color);
}

static int	get_color_with_light(t_obj_data *obj, t_minirt_data *data)
{
	t_rgb	rgb;
	int		i;
	double	a;

	i = -1;
	while (++i <= 2)
		rgb.rgb[i] = obj->color.rgb[i]
			* (data->ambient.rgb.rgb[i] * data->ambient.ratio);
	if (data->light.loaded == TRUE)
	{
		a = obj->angle;
		if (a > 1)
			a = 1;
		i = -1;
		while (++i <= 2)
		{
			rgb.rgb[i] += obj->color.rgb[i]
				* (data->light.rgb.rgb[i] * data->light.ratio) * a;
			if (rgb.rgb[i] > 1)
				rgb.rgb[i] = 1;
			else if (rgb.rgb[i] < -1)
				rgb.rgb[i] = -1;
		}
	}
	return (final_color(rgb));
}

static double	normal(t_ray ray, t_obj_data *obj)
{
	t_vec3	tmp_vector;

	tmp_vector = obj->cylinder->normal;
	return (fabs(dot(ray.direction, tmp_vector)));
}

int	calculate_light(t_minirt_data *data, t_obj_data *obj, t_ray old_ray)
{
	t_ray		ray;
	t_obj_data	new_obj;
	t_vec3		tmp_vector;
	double		light_distance;

	if (obj->inside == TRUE)
		return (final_color((t_rgb){{0, 0, 0}}));
	ray.origin = plus(mult_vec3_dub(old_ray.direction,
				obj->distance - 0.0001), old_ray.origin);
	light_distance = distance(ray.origin, data->light.origin);
	ray.direction = normalized(minus(data->light.origin, ray.origin));
	loop_objects(ray, data, &new_obj, TRUE);
	if (new_obj.distance < light_distance)
		return (get_color(obj->color, data));
	if (obj->sphere != NULL)
	{
		tmp_vector = normalized(minus(ray.origin, obj->sphere->origin));
		obj->angle = fabs(dot(ray.direction, tmp_vector));
	}
	else if (obj->plane != NULL)
		obj->angle = fabs(dot(ray.direction, obj->plane->direction));
	else if (obj->cylinder != NULL)
		obj->angle = normal(ray, obj);
	return (get_color_with_light(obj, data));
}
