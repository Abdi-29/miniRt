/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:20:48 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 15:20:48 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vec3.h"

t_vec3	plus(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vec3	minus(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_vec3	multiplication(t_vec3 a, t_vec3 b)
{
	t_vec3	c;

	c.x = a.x * b.x;
	c.y = a.y * b.y;
	c.z = a.z * b.z;
	return (c);
}

t_vec3	division(t_vec3 a, double t)
{
	t_vec3	c;

	c.x = a.x / t;
	c.y = a.y / t;
	c.z = a.z / t;
	return (c);
}

t_vec3	mult_vec3_dub(t_vec3 a, double t)
{
	t_vec3	c;

	c.x = a.x * t;
	c.y = a.y * t;
	c.z = a.z * t;
	return (c);
}
