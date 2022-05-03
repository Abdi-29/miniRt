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

# include "../xyz.h"

typedef struct s_camera
{
	t_xyz	coords;
	t_xyz	vector;
	int		fov;
}	t_camera;

#endif
