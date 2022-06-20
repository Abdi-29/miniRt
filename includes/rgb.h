/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgb.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:19:08 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 15:19:08 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGB_H
# define RGB_H

typedef union u_rgb
{
	struct
	{
		double	r;
		double	g;
		double	b;
	};
	double	rgb[3];
}	t_rgb;

#endif
