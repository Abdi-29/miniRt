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
# include "../xyz.h"
# include "../rgb.h"

typedef struct s_plane
{
	t_xyz	xyz;
	t_xyz	vector;
	t_rgb	rgb;
}	t_plane;

#endif
