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

static t_bool	cylinder_intersect(t_cylinder *cylinder, t_ray ray)
{
	double	len_one;
	double	len_two;

	get_delta(cylinder, ray);
	cylinder->delta.t_delta.discriminant = pow(cylinder->delta.delta[1], 2)
		- 4 * cylinder->delta.delta[0] * cylinder->delta.delta[2];
	if (cylinder->delta.t_delta.discriminant < 0)
		return (FALSE);
	len_one = (-cylinder->delta.delta[1] - sqrt(cylinder->delta.t_delta.discriminant))
		/ (2 * cylinder->delta.delta[0]);
	len_two = (-cylinder->delta.delta[1] + sqrt(cylinder->delta.t_delta.discriminant))
		/ (2 * cylinder->delta.delta[0]);
	if (len_one < len_two)
		cylinder->distance = len_one;
	else
		cylinder->distance = len_two;
	return (TRUE);
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
		if (cylinder->distance < obj->distance && cylinder->distance > 0)
		{
			obj->color = cylinder->rgb;
			obj->has_color = TRUE;
			obj->distance = cylinder->distance;
			obj->cylinder = cylinder;
			obj->plane = NULL;
			obj->sphere = NULL;
		}
		entry = entry->next;
	}
}
