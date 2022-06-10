/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 19:57:42 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/06 19:57:42 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "xyz.h"

t_xyz	plus(t_xyz a, t_xyz b);
t_xyz	minus(t_xyz a, t_xyz b);
t_xyz	multiplication(t_xyz a, t_xyz b);
t_xyz	division(t_xyz a, double t);
double	magnitute(t_xyz a);
double	dot(t_xyz a, t_xyz b);
t_xyz	mult_xyz_dub(t_xyz a, double t);
t_xyz	unit_vector(t_xyz a);
t_xyz	normalized(t_xyz a);
double	length(t_xyz a);
t_xyz	cross(t_xyz a, t_xyz b);
double	distance(t_xyz one, t_xyz two);

void	mat_init_axes(t_mat *in, const t_xyz forward);
t_xyz	mat_mult_dir(t_mat in, t_xyz dir);
t_mat	mat_transpose(t_mat in);

#endif
