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

t_bool	set_vector(t_xyz *xyz, const char **vectors);
t_bool	set_colors(t_rgb *rgb, const char **color);
t_bool	set_coords(t_xyz *xyz, const char **coords);
t_bool	set_view(t_camera *camera, char *view);

#endif
