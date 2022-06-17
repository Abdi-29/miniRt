/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 18:00:29 by abba          #+#    #+#                 */
/*   Updated: 2022/06/14 16:36:46 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ray.h"
#include <math.h>
#include "../../includes/vector.h"

static t_xyz	translate_normal(t_xyz direction, t_xyz normal)
{
	t_xyz	new_ray;
	t_mat	inverse;
	t_xyz	up;
	t_xyz	forward;

	forward = normalized(cross(normal, (t_xyz){{1, 0, 0}}));
	if (isnan(length(forward)) || length(forward) == 0.0)
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
	new_ray = normalized(mat_mult_dir(inverse, direction));
	return (new_ray);
}

static t_ray	translate_ray(t_ray ray, t_xyz normal, t_xyz origin)
{
	t_ray	new_ray;
	t_mat	inverse;
	t_xyz	up;
	t_xyz	forward;

	forward = normalized(cross(normal, (t_xyz){{1, 0, 0}}));
	if (isnan(length(forward)) || length(forward) == 0.0)
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
	inverse = mat_transpose(inverse);
	new_ray.origin = minus(ray.origin, origin);
	new_ray.origin = mat_mult_dir(inverse, new_ray.origin);
	new_ray.origin = plus(new_ray.origin, origin);
	new_ray.direction = normalized(mat_mult_dir(inverse, ray.direction));
	return (new_ray);
}

static void	prepare_formula(t_cylinder *cylinder, t_ray ray)
{
	t_xyz	oc;
	t_xyz	tmp;
	t_xyz	s_cross_d;

	tmp = (t_xyz){{0, 1, 0}};
	s_cross_d = cross(ray.direction, tmp);
	oc = minus(ray.origin, cylinder->xyz);
	cylinder->formula_storage.a = dot(s_cross_d, s_cross_d);
	cylinder->formula_storage.b = 2 * dot(s_cross_d,
			cross(oc, tmp));
	cylinder->formula_storage.c = dot(cross(oc, tmp),
			cross(oc, tmp)) - pow(cylinder->diameter / 2, 2);
}

static t_bool	inside_cylinder_height_and_assign_length(t_ray ray, t_cylinder *cylinder, double len)
{
	double	height;
	t_xyz	p;
	t_xyz	n;
	t_xyz	op;

	p = plus(ray.origin, mult_xyz_dub(ray.direction, len));
	n = (t_xyz){{p.xyz[0] - cylinder->xyz.t_s_xyz.x, 0.0, p.xyz[2]
		- cylinder->xyz.t_s_xyz.z}};
	op = plus(cylinder->xyz, n);
	height = length(minus(p, op));
	if (fabs(height) < cylinder->height / 2.0)
	{
		cylinder->distance = len;
		n = translate_normal(normalized(n), cylinder->vector);
		cylinder->normal = n;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	cylinder_intersect(t_cylinder *cylinder, t_ray ray)
{
	double	len_one;
	double	len_two;

	ray = translate_ray(ray, cylinder->vector, cylinder->xyz);
	prepare_formula(cylinder, ray);
	cylinder->formula_storage.discriminant = pow(cylinder->formula_storage.b, 2)
		- 4 * cylinder->formula_storage.a * cylinder->formula_storage.c;
	if (cylinder->formula_storage.discriminant < 0)
		return (FALSE);
	len_one = (-cylinder->formula_storage.b
			- sqrt(cylinder->formula_storage.discriminant))
		/ (2 * cylinder->formula_storage.a);
	len_two = (-cylinder->formula_storage.b
			+ sqrt(cylinder->formula_storage.discriminant))
		/ (2 * cylinder->formula_storage.a);
	if (inside_cylinder_height_and_assign_length(ray, cylinder, len_one))
		return (TRUE);
	return (inside_cylinder_height_and_assign_length(ray, cylinder, len_two));
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
