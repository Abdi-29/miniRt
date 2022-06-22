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
# include "vec3.h"
# include "./objects/camera.h"

t_bool	set_vector(t_vec3 *xyz, char **vectors);
t_bool	set_colors(t_rgb *rgb, char **color);
t_bool	set_coords(t_vec3 *xyz, char **coords);

#endif
