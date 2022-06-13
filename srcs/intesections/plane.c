/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 18:12:04 by abba          #+#    #+#                 */
/*   Updated: 2022/06/03 18:12:04 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rgb.h"
#include "../../includes/ray.h"
#include <math.h>
#include "../../includes/vector.h"

static double	hit_plane(t_xyz xyz, t_xyz vector, t_ray ray)
{
	double	d;

	d = dot(vector, ray.direction);
	if (fabs(d) > 0.0001)
	{
		d = dot((minus(xyz, ray.origin)), vector) / d;
		return (d);
	}
	return (INFINITY);
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