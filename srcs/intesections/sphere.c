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

#include "../../includes/ray.h"
#include <math.h>
#include "../../includes/vector.h"

//( x-cx ) ^2 + (y-cy) ^2 + (z-cz) ^ 2 < r^2
static t_bool	inside_sphere(t_sphere *sphere, t_ray ray)
{
	t_vec3	coords;
	double	rad;

	rad = sphere->diameter / 2;
	coords = minus(sphere->origin, ray.origin);
	coords = multiplication(coords, coords);
	return ((t_bool) coords.xyz[0] + coords.xyz[1] + coords.xyz[2] < rad * rad);
}

int	hit_sphere(t_sphere *sphere, double radius, t_ray ray, t_bool light)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	if (light == FALSE && inside_sphere(sphere, ray) == TRUE)
	{
		sphere->distance1 = 0;
		sphere->distance2 = 0;
		return (2);
	}
	oc = minus(sphere->origin, ray.origin);
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

void	update_obj(t_obj_data *obj, t_sphere *sphere, int result)
{
	obj->color = sphere->rgb;
	obj->has_color = TRUE;
	obj->distance = sphere->distance1;
	if (result == 2)
	{
		obj->distance = 0;
		obj->inside = TRUE;
	}
	obj->sphere = sphere;
	obj->plane = NULL;
	obj->cylinder = NULL;
}

void	loop_sphere(t_ray ray, t_list *entry, t_obj_data *obj, t_bool light)
{
	t_sphere	*sphere;
	int			result;

	while (entry)
	{
		sphere = entry->content;
		result = hit_sphere(sphere, sphere->diameter / 2.0, ray, light);
		if (result == FALSE)
		{
			entry = entry->next;
			continue ;
		}
		if (sphere->distance1 < 0)
			sphere->distance1 = sphere->distance2;
		if (sphere->distance1 < obj->distance || result == 2)
			update_obj(obj, sphere, result);
		entry = entry->next;
	}
}
