/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:20:48 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 15:20:48 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rgb.h"
#include "../includes/lib.h"

int	parse_color(char *color, t_bool *bool)
{
	int	nbr;

	nbr = ft_atoi(color, bool);
	if (bool == false || nbr < 0 || nbr > 250)
		*bool = false;
	return (nbr);
}

t_bool	set_colors(t_rgb *rgb, char *r, char *g, char *b)
{
	t_bool	bool;

	rgb->r = parse_color(r, &bool);
	if (bool == false)
		return (false);
	rgb->g = parse_color(g, &bool);
	if (bool == false)
		return (false);
	rgb->b = parse_color(b, &bool);
	if (bool == false)
		return (false);
	return (true);
}
