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
# include "../../includes/xyz.h"

t_xyz	plus(t_xyz a, t_xyz b);
t_xyz	minus(t_xyz a, t_xyz b);
t_xyz	multiplication(t_xyz a, t_xyz b);
t_xyz	division(t_xyz a, double t);
double	dot(t_xyz a, t_xyz b);
t_xyz	mult_xyz_dub(t_xyz a, double t);
t_xyz	unit_vector(t_xyz a);

#endif
