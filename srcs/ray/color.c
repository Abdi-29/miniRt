/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 19:24:08 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/06 19:24:08 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rgb.h"
#include "ray.h"

int	get_color(t_rgb rgb, double t)
{
	int	color;

	color = (int) rgb.t_s_rgb.r * 255;
	color = (color << 8) + (int) rgb.t_s_rgb.g * 255;
	color = (color << 8) + (int) rgb.t_s_rgb.b * 255;
	color = (color << 8) + (int)(100 * t);
	return (color);
}

int	ray_color(t_ray ray)
{
	t_rgb	rgb;
	double	t;

	t = 0.5 * (ray.direction.t_s_xyz.y + 1.0);
	rgb.t_s_rgb.r = 50;
	rgb.t_s_rgb.g = 50;
	rgb.t_s_rgb.b = 50;
	return (get_color(rgb, t - 1.0));
}
