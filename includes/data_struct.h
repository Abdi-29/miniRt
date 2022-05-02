/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_struct.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:16:24 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 15:16:24 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H
# include "objects/ambient.h"
# include "objects/camera.h"
# include "objects/cylinder.h"
# include "objects/light.h"
# include "objects/plane.h"
# include "objects/sphere.h"
# include "lib.h"

typedef struct s_minirt_data
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_list		*sphere_list;
	t_list		*plane_list;
	t_list		*cylinder_list;
}	t_minirt_data;

#endif
