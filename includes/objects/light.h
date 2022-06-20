/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 17:38:20 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 17:38:20 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "../vec3.h"
# include "../rgb.h"

typedef struct s_light
{
	t_vec3	origin;
	double	ratio;
	t_rgb	rgb;
	t_bool	loaded;
}	t_light;

#endif
