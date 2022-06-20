/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:16:54 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 15:16:54 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "../vec3.h"
# include "../bool.h"

typedef struct s_camera
{
	t_vec3	coords;
	t_vec3	direction;
	int		fov;
	t_bool	loaded;
}	t_camera;

#endif
