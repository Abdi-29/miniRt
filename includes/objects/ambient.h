/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ambient.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 17:36:23 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 17:36:23 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H
# include "../rgb.h"

typedef struct s_ambient
{
	double	ratio;
	t_rgb	rgb;
	t_bool	loaded;
}	t_ambient;

#endif
