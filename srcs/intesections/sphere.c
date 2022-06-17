/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 18:14:52 by abba          #+#    #+#                 */
/*   Updated: 2022/06/03 18:14:52 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rgb.h"
#include "../../includes/ray.h"
#include <math.h>
#include "../../includes/vector.h"

//( x-cx ) ^2 + (y-cy) ^2 + (z-cz) ^ 2 < r^2
static t_bool	inside_sphere(t_sphere *sphere, t_ray ray)
{
	t_xyz	coords;
	double	rad;

	rad = sphere->diameter / 2;
	coords = minus(sphere->xyz, ray.origin);
	coords = multiplication(coords, coords);
	return ((t_bool) coords.xyz[0] + coords.xyz[1] + coords.xyz[2] < rad * rad);
}

t_bool	hit_sphere(t_sphere *sphere, double radius, t_ray ray)
{
	t_xyz	oc;
	double	a;
	double	b;
	double	c;

	if (inside_sphere(sphere, ray) == TRUE)
	{
		sphere->distance1 = 0;
		sphere->distance2 = 0;
		sphere->inside = TRUE;
		return (TRUE);
	}
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
			obj->sphere = sphere;
			obj->plane = NULL;
			obj->cylinder = NULL;
			if (sphere->inside)
			{
				obj->inside = TRUE;
				break ;
			}
		}
		entry = entry->next;
	}
}