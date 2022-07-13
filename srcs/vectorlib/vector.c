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
	a.x /= len;
	a.y /= len;
	a.z /= len;
	return (a);
}
