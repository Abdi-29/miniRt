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
# include "../vec3.h"
# include "../rgb.h"
# include "../delta.h"

typedef struct s_cylinder
{
	t_vec3				origin;
	t_vec3				direction;
	t_rgb				rgb;
	t_formula_storage	formula_storage;
	double				diameter;
	double				height;
	double				distance;
	t_vec3				normal;
}	t_cylinder;

//typedef struct s_disk
//{
//    t_vec3				xyz;
//    t_vec3				vector;
//    t_rgb				rgb;
//    double				diameter;
//    double				distance;
//}               t_disk;

#endif
