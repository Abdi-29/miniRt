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

	color = (int)(rgb.t_s_rgb.r * ((data->ambient.rgb.t_s_rgb.r * 255)
				* data->ambient.ratio));
	color = (color << 8) + (int)(rgb.t_s_rgb.g
			* ((data->ambient.rgb.t_s_rgb.g * 255) * data->ambient.ratio));
	color = (color << 8) + (int)(rgb.t_s_rgb.b
			* ((data->ambient.rgb.t_s_rgb.b * 255) * data->ambient.ratio));
	color = (color << 8) + 255;
	return (color);
}

static int	get_color_with_light(t_obj_data *obj, t_minirt_data *data)
{
	int		color;
	t_rgb	rgb;
	int		i;
	double	a;

	a = obj->angle;
	if (a > 1)
		a = 1;
	rgb = obj->color;
	i = -1;
	while (++i <= 2)
		rgb.rgb[i] = obj->color.rgb[i]
			* (data->ambient.rgb.rgb[i] * data->ambient.ratio);
	i = -1;
	while (++i <= 2)
	{
		rgb.rgb[i] += obj->color.rgb[i]
			* (data->light.rgb.rgb[i] * data->light.ratio) * a;
		if (rgb.rgb[i] > 1)
			rgb.rgb[i] = 1;
	}
	color = (int)(rgb.t_s_rgb.r * 255);
	color = (color << 8) + (int)(rgb.t_s_rgb.g * 255);
	color = (color << 8) + (int)(rgb.t_s_rgb.b * 255);
	color = (color << 8) + 255;
	return (color);
}

static double	normal(t_ray ray, t_obj_data *obj)
{
	t_vec3	tmp_vector;

	tmp_vector = obj->cylinder->normal;
	return (fabs(dot(ray.direction, tmp_vector)));
}

int	tem(t_minirt_data *data, t_obj_data *obj, t_ray old_ray)
{
	t_ray		ray;
	t_obj_data	new_obj;
	t_vec3		tmp_vector;
	double		light_distance;

	ray.origin = plus(mult_vec3_dub(old_ray.direction,
				obj->distance - 0.0001), old_ray.origin);
	light_distance = distance(ray.origin, data->light.origin);
	ray.direction = normalized(minus(data->light.origin, ray.origin));
	loop_objects(ray, data, &new_obj);
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
