/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 20:34:01 by abba          #+#    #+#                 */
/*   Updated: 2022/05/03 20:34:01 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/objects/camera.h"
#include "../includes/lib.h"
#include "../includes/util.h"

t_bool set_view(t_camera *camera, char *view)
{
	int 	nbr;
	t_bool success;

	nbr = ft_atoi(view, &success);
	if (success == false || nbr < 0 || nbr > 180)
		err_exit(1, "Error\nOut of range\n");
	camera->fov = nbr;
	return (true);
}