/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 17:45:08 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 17:45:08 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
# include "../xyz.h"
# include "../rgb.h"
# include "../delta.h"

typedef struct s_cylinder
{
	t_xyz	xyz;
	t_xyz	vector;
	t_rgb	rgb;
	t_delta	delta;
	double	diameter;
	double	height;
	double	distance;
}	t_cylinder;

#endif
