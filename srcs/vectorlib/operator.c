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

#include "../../includes/xyz.h"

t_xyz	plus(t_xyz a, t_xyz b)
{
	t_xyz	c;

	c.t_s_xyz.x = a.t_s_xyz.x + b.t_s_xyz.x;
	c.t_s_xyz.y = a.t_s_xyz.y + b.t_s_xyz.y;
	c.t_s_xyz.z = a.t_s_xyz.z + b.t_s_xyz.z;
	return (c);
}

t_xyz	minus(t_xyz a, t_xyz b)
{
	t_xyz	c;

	c.t_s_xyz.x = a.t_s_xyz.x - b.t_s_xyz.x;
	c.t_s_xyz.y = a.t_s_xyz.y - b.t_s_xyz.y;
	c.t_s_xyz.z = a.t_s_xyz.z - b.t_s_xyz.z;
	return (c);
}

t_xyz	multiplication(t_xyz a, t_xyz b)
{
	t_xyz	c;

	c.t_s_xyz.x = a.t_s_xyz.x * b.t_s_xyz.x;
	c.t_s_xyz.y = a.t_s_xyz.y * b.t_s_xyz.y;
	c.t_s_xyz.z = a.t_s_xyz.z * b.t_s_xyz.z;
	return (c);
}

t_xyz	division(t_xyz a, double t)
{
	t_xyz	c;

	c.t_s_xyz.x = a.t_s_xyz.x / t;
	c.t_s_xyz.y = a.t_s_xyz.y / t;
	c.t_s_xyz.z = a.t_s_xyz.z / t;
	return (c);
}

t_xyz	mult_xyz_dub(t_xyz a, double t)
{
	t_xyz	c;

	c.t_s_xyz.x = a.t_s_xyz.x * t;
	c.t_s_xyz.y = a.t_s_xyz.y * t;
	c.t_s_xyz.z = a.t_s_xyz.z * t;
	return (c);
}
