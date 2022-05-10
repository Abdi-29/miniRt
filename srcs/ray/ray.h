/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 19:14:58 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/06 19:14:58 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "../../includes/xyz.h"
# include "../../includes/data_struct.h"

typedef struct s_ray
{
	t_xyz		origin;
	t_xyz		direction;
	t_sphere	sphere;
	t_list		*sphere_list;
}	t_ray;

int		ray_color(t_ray ray, t_minirt_data *data);
t_ray	create_ray(t_minirt_data *data, int i, int j);
t_xyz	lower_left_corner(t_minirt_data *data);

#endif
