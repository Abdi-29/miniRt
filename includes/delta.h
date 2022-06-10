/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   formula_storage.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 20:22:32 by abba          #+#    #+#                 */
/*   Updated: 2022/06/03 20:22:32 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DELTA_H
# define DELTA_H

typedef struct s_formula_storage
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
}	t_formula_storage;

#endif