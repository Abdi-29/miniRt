/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   xyz.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:18:01 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 15:18:01 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef XYZ_H
# define XYZ_H

typedef union u_xyz
{
	struct s_xyz
	{
		double	x;
		double	y;
		double	z;
	}		t_s_xyz;
	double	xyz[3];
}			t_xyz;

#endif
