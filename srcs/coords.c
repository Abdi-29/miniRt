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

#include "../includes/xyz.h"
#include "../includes/bool.h"
#include "../libft/libft.h"

int	parse_coords(char *color, t_bool *bool)
{
	double	nbr;

	nbr = ft_atod(color, bool);
	if (bool == false || nbr < 0 || nbr > 250)
		*bool = false;
	return (nbr);
}

t_bool	set_colors(t_xyz *xyz, char *x, char *y, char *z)
{
	t_bool	bool;

	xyz->x = parse_coords(x, &bool);
	if (bool == false)
		return (false);
	xyz->y = parse_coords(y, &bool);
	if (bool == false)
		return (false);
	xyz->z = parse_coords(z, &bool);
	if (bool == false)
		return (false);
	return (true);
}
