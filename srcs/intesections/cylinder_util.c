/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder_util.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 17:55:19 by abba          #+#    #+#                 */
/*   Updated: 2022/06/20 17:55:19 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ray.h"
#include <math.h>
#include "../../includes/vector.h"

void	prepare_formula(t_cylinder *cylinder, t_ray ray)
{
	t_vec3	oc;
	t_vec3	tmp;
	t_vec3	s_cross_d;

	tmp = (t_vec3){{0, 1, 0}};
	s_cross_d = cross(ray.direction, tmp);
	oc = minus(ray.origin, cylinder->origin);
	cylinder->formula_storage.a = dot(s_cross_d, s_cross_d);
	cylinder->formula_storage.b = 2.0 * dot(s_cross_d,
			cross(oc, tmp));
	cylinder->formula_storage.c = dot(cross(oc, tmp),
			cross(oc, tmp)) - pow(cylinder->diameter / 2, 2);
}
