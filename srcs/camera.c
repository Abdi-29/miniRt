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

t_bool set_fov(t_camera *camera, char *fov)
{
	int 	nbr;
	t_bool success;

	nbr = ft_atoi(fov, &success);
	if (success == false || nbr < 0 || nbr > 180)
		err_exit(1, "Error\nFOV out of range [%s]\n", fov);
	camera->fov = nbr;
	return (true);
}