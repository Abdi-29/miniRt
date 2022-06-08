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
# include "xyz.h"
# include "data_struct.h"
# include "bool.h"

typedef struct s_obj_data
{
	t_rgb		color;
	double		distance;
	t_bool		has_color;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	double		angle;
}	t_obj_data;

typedef struct s_ray
{
	t_xyz		origin;
	t_xyz		direction;
}	t_ray;

typedef struct s_screen
{
	double	screen_x;
	double	screen_y;
	double	pixel_camera_x;
	double	pixel_camera_y;
	double	image_ratio;
}	t_screen;

int		ray_color(t_ray ray, t_minirt_data *data);
t_ray	create_ray(t_minirt_data *data, int i, int j);
t_xyz	init_coords(double x, double y, double z);

void	loop_cylinder(t_ray ray, t_list *entry, t_obj_data *obj);
void	loop_plane(t_ray ray, t_list *entry, t_obj_data *obj);
void	loop_sphere(t_ray ray, t_list *entry, t_obj_data *obj);
void	loop_objects(t_ray ray, t_minirt_data *data, t_obj_data *obj);

int		tem(t_minirt_data *data, t_obj_data *obj, t_ray old_ray);
int		get_color(t_rgb rgb, t_minirt_data *data);

#endif
