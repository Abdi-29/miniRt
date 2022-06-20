/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 19:30:08 by abba          #+#    #+#                 */
/*   Updated: 2022/05/06 19:30:08 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vec3.h"
#include "../../includes/vector.h"
#include <math.h>

t_vec3	cross(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

double	length(t_vec3 a)
{
	return (sqrt((a.x * a.x
				+ a.y * a.y
				+ a.z * a.z)));
}

t_mat	mat_transpose(t_mat in)
{
	in.mat[0][1] += in.mat[1][0];
	in.mat[1][0] = in.mat[0][1] - in.mat[1][0];
	in.mat[0][1] -= in.mat[1][0];
	in.mat[0][2] += in.mat[2][0];
	in.mat[2][0] = in.mat[0][2] - in.mat[2][0];
	in.mat[0][2] -= in.mat[2][0];
	in.mat[2][1] += in.mat[1][2];
	in.mat[1][2] = in.mat[2][1] - in.mat[1][2];
	in.mat[2][1] -= in.mat[1][2];
	return (in);
}

t_vec3	mat_mult_dir(t_mat in, t_vec3 dir)
{
	return ((t_vec3){{dir.xyz[0] * in.mat[0][0]
		+ dir.xyz[1] * in.mat[1][0]
		+ dir.xyz[2] * in.mat[2][0],
		dir.xyz[0] * in.mat[0][1]
		+ dir.xyz[1] * in.mat[1][1]
		+ dir.xyz[2] * in.mat[2][1],
		dir.xyz[0] * in.mat[0][2]
		+ dir.xyz[1] * in.mat[1][2]
		+ dir.xyz[2] * in.mat[2][2]}});
}

void	mat_init_axes(t_mat *in, const t_vec3 forward)
{
	t_vec3	right;
	t_vec3	up;

	in->mat[2][0] = forward.xyz[0];
	in->mat[2][1] = forward.xyz[1];
	in->mat[2][2] = forward.xyz[2];
	right = cross(forward, (t_vec3){{0, 1, 0}});
	if (isnan(length(right)))
		right = (t_vec3){{1, 0, 0}};
	up = cross(right, forward);
	in->mat[0][0] = right.xyz[0];
	in->mat[0][1] = right.xyz[1];
	in->mat[0][2] = right.xyz[2];
	in->mat[1][0] = up.xyz[0];
	in->mat[1][1] = up.xyz[1];
	in->mat[1][2] = up.xyz[2];
}

t_vec3	unit_vector(t_vec3 a)
{
	return (division(a, length(a)));
}

double	dot(t_vec3 a, t_vec3 b)
{
	double	c;

	c = a.x * b.x
		+ a.y * b.y
		+ a.z * b.z;
	return (c);
}

t_vec3	normalized(t_vec3 a)
{
	double	len;

	len = length(a);
	if (isnan(len))
		a.z += 0.1;
	a.x /= len;
	a.y /= len;
	a.z /= len;
	return (a);
}

double	magnitute(t_vec3 a)
{
	return (sqrt((a.xyz[0] * a.xyz[0])
			+ (a.xyz[1] * a.xyz[1])
			+ (a.xyz[2] * a.xyz[2])));
}

double	distance(t_vec3 one, t_vec3 two)
{
	t_vec3	res;

	res = minus(one, two);
	return (length(res));
}
