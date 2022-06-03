/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delta.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 20:22:32 by abba          #+#    #+#                 */
/*   Updated: 2022/06/03 20:22:32 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELTA_H
# define DELTA_H

typedef union u_delta
{
	struct s_delta
	{
		double	a;
		double	b;
		double	c;
		double	discriminant;
	}		t_s_rgb;
	double	delta[3];
}					t_delta;

#endif