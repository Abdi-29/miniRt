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
#include "../includes/util.h"

static int	parse_color(const char *color, t_bool *success)
{
	int	nbr;

	nbr = ft_atoi(color, success);
	if (nbr < 0 || nbr > 255)
		*success = false;
	return (nbr);
}

void	set_colors(t_rgb *rgb, char **color)
{
	t_bool		valid;
	const char	*temp[3] = {color[0], color[1], color[2]};
	int			i;

	i = 0;
	while (i < 3)
	{
		rgb->rgb[i] = parse_color(temp[i], &valid);
		if (valid == false)
			err_exit(1, "Error\nInvalid double [%s].\n", color[i]);
		i++;
	}
}
