/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:18 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:18 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "bool.h"
# include "../libft/libft.h"
# include "rgb.h"
# include "xyz.h"
# include "./objects/camera.h"

void	set_vector(t_xyz *xyz, char **vectors);
void	set_colors(t_rgb *rgb, char **color);
void	set_coords(t_xyz *xyz, char **coords);
void	set_fov(t_camera *camera, char *fov);

#endif
