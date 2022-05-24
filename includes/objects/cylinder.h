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

typedef struct s_cylinder
{
	t_xyz	xyz;
	t_xyz	vector;
	double	diameter;
	double	height;
	t_rgb	rgb;
	double	distance1;
	double	distance2;
}	t_cylinder;

#endif
