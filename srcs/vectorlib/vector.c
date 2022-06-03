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

#include "../../includes/xyz.h"
#include "../../includes/vector.h"
#include <math.h>

t_xyz	cross(t_xyz a, t_xyz b)
{
	t_xyz	c;

	c.t_s_xyz.x = a.t_s_xyz.y * b.t_s_xyz.z - a.t_s_xyz.z * b.t_s_xyz.y;
	c.t_s_xyz.y = a.t_s_xyz.z * b.t_s_xyz.x - a.t_s_xyz.x * b.t_s_xyz.z;
	c.t_s_xyz.z = a.t_s_xyz.x * b.t_s_xyz.y - a.t_s_xyz.y * b.t_s_xyz.x;
	return (c);
}

double	length(t_xyz a)
{
	return (sqrt((a.t_s_xyz.x * a.t_s_xyz.x
				+ a.t_s_xyz.y * a.t_s_xyz.y
				+ a.t_s_xyz.z * a.t_s_xyz.z)));
}

t_xyz	mat_mult_dir(t_mat in, t_xyz dir)
{
	return ((t_xyz){{dir.xyz[0] * in.mat[0][0]
		+ dir.xyz[1] * in.mat[1][0]
		+ dir.xyz[2] * in.mat[2][0],
		dir.xyz[0] * in.mat[0][1]
		+ dir.xyz[1] * in.mat[1][1]
		+ dir.xyz[2] * in.mat[2][1],
		dir.xyz[0] * in.mat[0][2]
		+ dir.xyz[1] * in.mat[1][2]
		+ dir.xyz[2] * in.mat[2][2]}});
}

void	mat_init_axes(t_mat *in, const t_xyz forward)
{
	t_xyz	right;
	t_xyz	up;

	in->mat[2][0] = forward.xyz[0];
	in->mat[2][1] = forward.xyz[1];
	in->mat[2][2] = forward.xyz[2];
	right = cross(forward, (t_xyz){{0, 1, 0}});
	if (isnan(length(right)))
		right = (t_xyz){{1, 0, 0}};
	up = cross(right, forward);
	in->mat[0][0] = right.xyz[0];
	in->mat[0][1] = right.xyz[1];
	in->mat[0][2] = right.xyz[2];
	in->mat[1][0] = up.xyz[0];
	in->mat[1][1] = up.xyz[1];
	in->mat[1][2] = up.xyz[2];
}

t_xyz	unit_vector(t_xyz a)
{
	return (division(a, length(a)));
}

double	dot(t_xyz a, t_xyz b)
{
	double	c;

	c = a.t_s_xyz.x * b.t_s_xyz.x
		+ a.t_s_xyz.y * b.t_s_xyz.y
		+ a.t_s_xyz.z * b.t_s_xyz.z;
	return (c);
}

t_xyz	normalized(t_xyz a)
{
	double	len;

	len = length(a);
	if (isnan(len))
		a.t_s_xyz.z += 0.1;
	a.t_s_xyz.x /= len;
	a.t_s_xyz.y /= len;
	a.t_s_xyz.z /= len;
	return (a);
}

double	magnitute(t_xyz a)
{
	return (sqrt((a.xyz[0] * a.xyz[0])
			+ (a.xyz[1] * a.xyz[1])
			+ (a.xyz[2] * a.xyz[2])));
}

double	distance(t_xyz one, t_xyz two)
{
	t_xyz	res;

	res = minus(one, two);
	return (length(res));
}
