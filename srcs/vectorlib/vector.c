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
#include "../../includes/lib.h"
#include "../../includes/util.h"
#include "vector.h"

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
	return (a.t_s_xyz.x + a.t_s_xyz.y + a.t_s_xyz.z);
}

t_xyz	unit_vector(t_xyz a)
{
	return (division(a, length(a)));
}

double	dot(t_xyz a, t_xyz b)
{
	double	c;

	c = a.t_s_xyz.x * b.t_s_xyz.x + \
		a.t_s_xyz.y * b.t_s_xyz.y + \
		a.t_s_xyz.z * b.t_s_xyz.z;
	return (c);
}
