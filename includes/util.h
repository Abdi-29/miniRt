/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 18:06:24 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 18:06:24 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H
# include "bool.h"

int		func(char c);
void	err_exit(int status, const char *str, ...);
int		arr_len(const char **arr);
t_bool	range(double a, double b, double value);
t_bool	is_valid(char **coordinates, char **vector, char **views);
t_bool	ratio_range(double min, double max, double value);
char	**split_helper(char *str, int len);

#endif
