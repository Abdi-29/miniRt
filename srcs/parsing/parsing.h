/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 18:40:56 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 18:40:56 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "../../includes/lib.h"
# include "../../includes/data_struct.h"

void	parse_file(char *file, t_minirt_data *data);
void	parse_lines(t_list **head, t_minirt_data *data);
void	parse_a(char **arr, int len, char *line, t_minirt_data *data);
void	parse_c(char **arr, int len, char *line, t_minirt_data *data);
void	parse_l(char **arr, int len, char *line, t_minirt_data *data);
void	parse_pl(char **arr, int len, char *line, t_minirt_data *data);
void	parse_sp(char **arr, int len, char *line, t_minirt_data *data);
void	parse_cy(char **arr, int len, char *line, t_minirt_data *data);

#endif
