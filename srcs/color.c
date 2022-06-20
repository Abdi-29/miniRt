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
		*success = FALSE;
	return (nbr);
}

t_bool	set_colors(t_rgb *rgb, char **color)
{
	t_bool		valid;
	const char	*temp[3] = {color[0], color[1], color[2]};
	int			i;

	i = 0;
	while (i < 3)
	{
		rgb->rgb[i] = ((double)parse_color(temp[i], &valid)) / 255.0;
		if (valid == FALSE)
			err_exit(1, "Error\nInvalid color [%s].\n", color[i]);
		i++;
	}
    free_array(color);
	return (TRUE);
}
