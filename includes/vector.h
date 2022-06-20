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
# include "vec3.h"

t_vec3	plus(t_vec3 a, t_vec3 b);
t_vec3	minus(t_vec3 a, t_vec3 b);
t_vec3	multiplication(t_vec3 a, t_vec3 b);
t_vec3	division(t_vec3 a, double t);
double	magnitute(t_vec3 a);
double	dot(t_vec3 a, t_vec3 b);
t_vec3	mult_vec3_dub(t_vec3 a, double t);
t_vec3	unit_vector(t_vec3 a);
t_vec3	normalized(t_vec3 a);
double	length(t_vec3 a);
t_vec3	cross(t_vec3 a, t_vec3 b);
double	distance(t_vec3 one, t_vec3 two);

void	mat_init_axes(t_mat *in, const t_vec3 forward);
t_vec3	mat_mult_dir(t_mat in, t_vec3 dir);
t_mat	mat_transpose(t_mat in);

#endif
