/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 17:44:04 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 17:44:04 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include "../vec3.h"
# include "../rgb.h"

typedef struct s_plane
{
	t_vec3	origin;
	t_vec3	direction;
	t_rgb	rgb;
}	t_plane;

#endif
