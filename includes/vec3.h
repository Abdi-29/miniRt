/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 13:51:12 by abba          #+#    #+#                 */
/*   Updated: 2022/06/20 13:51:12 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_mat
{
	double	mat[3][3];
}	t_mat;

typedef union u_xyz
{
	struct
	{
		double	x;
		double	y;
		double	z;
	};
	double	xyz[3];
}	t_vec3;

#endif
