/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light_util.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 17:45:40 by abba          #+#    #+#                 */
/*   Updated: 2022/06/20 17:45:40 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ray.h"
#include "../../includes/vector.h"

double	distance(t_vec3 one, t_vec3 two)
{
	t_vec3	res;

	res = minus(one, two);
	return (length(res));
}
