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
# include "../../includes/bool.h"

typedef struct s_obj_data
{
	t_rgb	color;
	double	distance;
	t_bool	has_color;
}	t_obj_data;

typedef struct s_ray
{
	t_xyz		origin;
	t_xyz		direction;
}	t_ray;

int		ray_color(t_ray ray, t_minirt_data *data);
t_ray	create_ray(t_minirt_data *data, int i, int j);
t_xyz	lower_left_corner(t_minirt_data *data);
t_xyz	init_coords(double x, double y, double z);
t_xyz	cross(t_xyz a, t_xyz b);

#endif
