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
	t_xyz				xyz;
	t_xyz				vector;
	t_rgb				rgb;
	t_formula_storage	formula_storage;
	double				diameter;
	double				height;
	double				distance;
	t_xyz				normal;
}	t_cylinder;

//cap 1:
//	vector = cylinder->vector;
//	xyz = cylinder->xyz + vector * (cylinder->height / 2.);
//	diameter = cylinder->diameter;
//
//cap 2:
//	vector = cylinder->vector * -1;
//	xyz = cylinder->xyz + vector * (cylinder->height / 2.);
//	diameter = cylinder->diameter;


#endif
