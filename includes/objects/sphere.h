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
# include "../xyz.h"
# include "../rgb.h"

# define TYPE_SPHERE 0

//typedef struct s_is
//{
//	bool	(*intersect)(t_ray *ray, void *data, float *t);
//	void	*data;	//	t_sphere or t_plane
//	vec3	hit;
//	vec3 	normal;
//	t_rgb	color;
//}	t_is;
//
//while (list != NULL)
//{
//	t_is intersection_data = list->content;
//
//	intersection_data.intersect(ray, intersection_data.data)
//}

typedef struct s_sphere
{
	t_xyz	xyz;
	double	diameter;
	t_rgb	rgb;
	double	distance1;
	double	distance2;
}	t_sphere;

#endif
