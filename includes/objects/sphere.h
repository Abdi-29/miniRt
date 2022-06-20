/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 17:41:18 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 17:41:18 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "../vec3.h"
# include "../rgb.h"

typedef struct s_sphere
{
	t_vec3	origin;
	double	diameter;
	t_rgb	rgb;
	double	distance1;
	double	distance2;
}	t_sphere;

#endif
