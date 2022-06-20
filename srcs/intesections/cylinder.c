/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 18:00:29 by abba          #+#    #+#                 */
/*   Updated: 2022/06/18 20:16:49 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ray.h"
#include <math.h>
#include "../../includes/vector.h"
#define EPSILON 0.0001

static t_vec3	translate_normal(t_vec3 direction, t_vec3 normal)
{
	t_vec3	new_ray;
	t_mat	inverse;
	t_vec3	up;
	t_vec3	forward;

	forward = normalized(cross(normal, (t_vec3){{1, 0, 0}}));
	if (isnan(length(forward)) || length(forward) == 0.0)
		forward = (t_vec3){{0, 1, 0}};
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
	// inverse = mat_transpose(inverse);
	new_ray = normalized(mat_mult_dir(inverse, direction));
	return (new_ray);
}

static t_ray	translate_ray(t_ray ray, t_vec3 normal, t_vec3 origin)
{
	t_ray	new_ray;
	t_mat	inverse;
	t_vec3	up;
	t_vec3	forward;

	forward = normalized(cross(normal, (t_vec3){{1, 0, 0}}));
	if (isnan(length(forward)) || length(forward) == 0.0)
		forward = (t_vec3){{0, 1, 0}};
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
	t_vec3	oc;
	t_vec3	tmp;
	t_vec3	s_cross_d;

	tmp = (t_vec3){{0,1,0}};
	s_cross_d = cross(ray.direction, tmp);
	oc = minus(ray.origin, cylinder->origin);
	cylinder->formula_storage.a = dot(s_cross_d, s_cross_d);
	cylinder->formula_storage.b = 2.0 * dot(s_cross_d,
			cross(oc, tmp));
	cylinder->formula_storage.c = dot(cross(oc, tmp),
			cross(oc, tmp)) - pow(cylinder->diameter / 2, 2);
}

static t_bool	inside_cylinder_height_and_assign_length(t_ray ray, t_cylinder *cylinder, double len)
{
	double	height;
	t_vec3	p;
	t_vec3	n;
	t_vec3	op;

	p = plus(ray.origin, mult_vec3_dub(ray.direction, len));
	n = (t_vec3){{p.xyz[0] - cylinder->origin.x, 0.0, p.xyz[2]
		- cylinder->origin.z}};
	op = plus(cylinder->origin, n);
	height = length(minus(p, op));
	if (fabs(height) < cylinder->height / 2.0)
	{
		cylinder->distance = len;
		n = translate_normal(normalized(n), cylinder->direction);
		cylinder->normal = n; //mult_vec3_dub(normalized(n), -1.0);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	cylinder_intersect(t_cylinder *cylinder, t_ray ray)
{
	double	len_one;
	double	len_two;

	ray = translate_ray(ray, cylinder->direction, cylinder->origin);
	prepare_formula(cylinder, ray);
	cylinder->formula_storage.discriminant = pow(cylinder->formula_storage.b, 2)
		- 4 * cylinder->formula_storage.a * cylinder->formula_storage.c;
	if (cylinder->formula_storage.discriminant < EPSILON)
		return (FALSE);
	len_one = (-cylinder->formula_storage.b
			- sqrt(cylinder->formula_storage.discriminant))
		/ (2.0 * cylinder->formula_storage.a);
	len_two = (-cylinder->formula_storage.b
			+ sqrt(cylinder->formula_storage.discriminant))
		/ (2.0 * cylinder->formula_storage.a);
	if (len_one < 0)
		len_one = len_two;	
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
