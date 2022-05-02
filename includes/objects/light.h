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
# include "../xyz.h"
# include "../rgb.h"

typedef struct s_light
{
	t_xyz	xyz;
	double	ratio;
	t_rgb	rgb;
}	t_light;

#endif
