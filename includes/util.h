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
# include "parser.h"

int		func(char c);
void	err_exit(int status, const char *str, ...);
int		arr_len(const char **arr);
t_bool	range(double a, double b, double value);
t_bool	is_valid(char **coordinates, char **vector, char **views);
char	**split_helper(const char **str, int pos, int len);
void	start_window(t_minirt_data *data);

#endif
