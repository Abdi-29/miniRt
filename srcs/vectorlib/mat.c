/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 17:40:22 by abba          #+#    #+#                 */
/*   Updated: 2022/06/20 17:40:22 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vec3.h"
#include "../../includes/vector.h"
#include <math.h>

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
	right = normalized(cross(forward, (t_vec3){{0, 1, 0}}));
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
