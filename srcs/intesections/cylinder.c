/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                          :+:    :+:           */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 18:00:29 by abba          #+#    #+#                 */
/*   Updated: 2022/06/05 17:14:08 by abba            ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rgb.h"
#include "../../includes/ray.h"
#include <math.h>
#include "../../includes/vector.h"

static void	get_delta(t_cylinder *cylinder, t_ray ray)
{
	t_xyz	oc;
	t_ray	new_ray;

	new_ray.origin = ray.origin;
	cylinder->vector = normalized(cylinder->vector);
	new_ray.direction = cross(ray.direction, cylinder->vector);
	oc = minus(ray.origin, cylinder->xyz);
	cylinder->delta.delta[0] = dot(new_ray.direction, new_ray.direction);
	cylinder->delta.delta[1] = 2 * dot(new_ray.direction, cross(oc,
				cylinder->vector));
	cylinder->delta.delta[2] = dot(cross(oc, cylinder->vector),
			cross(oc, cylinder->vector)) - pow(cylinder->diameter / 2, 2);
}

static t_bool	cylinder_hit_point(t_ray ray, t_cylinder *cylinder, double max)
{
	t_xyz	point;
	t_xyz	len;

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

static t_bool	cylinder_intersect(t_cylinder *cylinder, t_ray ray)
{
	double	t[2];
	double	max;

	get_delta(cylinder, ray);
	cylinder->delta.t_s_rgb.discriminant = pow(cylinder->delta.delta[1], 2)
		- 4 * cylinder->delta.delta[0] * cylinder->delta.delta[2];
	if (cylinder->delta.t_s_rgb.discriminant < 0)
		return (FALSE);
	t[0] = (-cylinder->delta.delta[1] - sqrt(cylinder->delta.t_s_rgb.discriminant))
		/ (2 * cylinder->delta.delta[0]);
	t[1] = (-cylinder->delta.delta[1] + sqrt(cylinder->delta.t_s_rgb.discriminant))
		/ (2 * cylinder->delta.delta[0]);
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
