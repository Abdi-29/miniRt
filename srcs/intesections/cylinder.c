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
#include <stdio.h>

static t_ray	translate_ray(t_ray ray, t_xyz normal, t_xyz origin)
{
	t_ray	new_ray;
	t_mat	inverse;
	t_xyz	up;
	t_xyz	forward;

	//printf("%f %f %f\n", normal.xyz[0], normal.xyz[1], normal.xyz[2]);
	forward = normalized(cross(normal, (t_xyz){{1, 0, 0}}));
	if (length(forward) == 0.0)
		forward = (t_xyz){{0, 1, 0}};
	up = normalized(cross(forward, normal));
	inverse.mat[2][0] = forward.xyz[0];
	inverse.mat[2][1] = forward.xyz[1];
	inverse.mat[2][2] = forward.xyz[2];
	inverse.mat[1][0] = normal.xyz[0];
	inverse.mat[1][1] = normal.xyz[1];
	inverse.mat[1][2] = normal.xyz[2];
	inverse.mat[0][0] = up.xyz[0];
	inverse.mat[0][1] = up.xyz[1];
	inverse.mat[0][2] = up.xyz[2];

	new_ray.origin = minus(ray.origin, origin);
	new_ray.origin = mat_mult_dir(inverse, new_ray.origin);
	new_ray.origin = plus(new_ray.origin, origin);

	//inverse = mat_transpose(inverse);
	new_ray.direction = normalized(mat_mult_dir(inverse, ray.direction));
	return (new_ray);
}

static t_ray	get_delta(t_cylinder *cylinder, t_ray ray)
{
	t_xyz	oc;
	t_ray	new_ray;
	t_xyz	tmp = (t_xyz){{0, 1, 0}};

	new_ray.origin = ray.origin;
	new_ray.direction = cross(ray.direction, tmp);
	oc = minus(ray.origin, cylinder->xyz);
	cylinder->delta.delta[0] = dot(new_ray.direction, new_ray.direction);
	cylinder->delta.delta[1] = 2 * dot(new_ray.direction, cross(oc,
				tmp));
	cylinder->delta.delta[2] = dot(cross(oc, tmp),
			cross(oc, tmp)) - pow(cylinder->diameter / 2, 2);
	new_ray.origin = ray.origin;
	new_ray.direction = ray.direction;
	return (new_ray);
}


static t_bool	cylinder_intersect(t_cylinder *cylinder, t_ray ray)
{
	double	len_one;
	double	len_two;


	ray = translate_ray(ray, cylinder->vector, cylinder->xyz);
	get_delta(cylinder, ray);
	cylinder->delta.t_delta.discriminant = pow(cylinder->delta.delta[1], 2)
		- 4 * cylinder->delta.delta[0] * cylinder->delta.delta[2];
	if (cylinder->delta.t_delta.discriminant < 0)
		return (FALSE);
	len_one = (-cylinder->delta.delta[1] - sqrt(cylinder->delta.t_delta.discriminant))
		/ (2 * cylinder->delta.delta[0]);
	if (len_one < 0)
		return (FALSE);

	t_xyz	p = plus(ray.origin, mult_xyz_dub(ray.direction, len_one));
	t_xyz	n = (t_xyz){{p.xyz[0] - cylinder->xyz.t_s_xyz.x, 0.0, p.xyz[2] - cylinder->xyz.t_s_xyz.z}};

	t_xyz	op = plus(cylinder->xyz, n);
	float	height = length(minus(p, op));

	if (height < cylinder->height / 2.)
	{
		cylinder->distance = len_one;
		cylinder->normal = normalized(n);
		cylinder->normal = mult_xyz_dub(normalized(n), -1.);
		return (TRUE);
	}
	len_two = (-cylinder->delta.delta[1] + sqrt(cylinder->delta.t_delta.discriminant))
		/ (2 * cylinder->delta.delta[0]);
	p = plus(ray.origin, mult_xyz_dub(ray.direction, len_two));
	n = (t_xyz){{p.xyz[0] - cylinder->xyz.t_s_xyz.x, 0.0, p.xyz[2] - cylinder->xyz.t_s_xyz.z}};
	op = plus(cylinder->xyz, n);
	height = length(minus(p, op));
	if (height < cylinder->height / 2.)
	{
		cylinder->distance = len_two;
		cylinder->normal = mult_xyz_dub(normalized(n), -1.);
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
