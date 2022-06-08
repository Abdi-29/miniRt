/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 18:55:32 by abba          #+#    #+#                 */
/*   Updated: 2022/05/03 18:55:32 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lib.h"
# include "data_struct.h"

typedef struct s_parser
{
	char	*option;
	void	(*t_function_pointer)(char **arr, int len, char *line,
			t_minirt_data *data);
}	t_parser;

void	parse_file(char *file, t_minirt_data *data);
void	parse_lines(t_list **head, t_minirt_data *data);
void	parse_a(char **arr, int len, char *line, t_minirt_data *data);
void	parse_c(char **arr, int len, char *line, t_minirt_data *data);
void	parse_l(char **arr, int len, char *line, t_minirt_data *data);
void	parse_pl(char **arr, int len, char *line, t_minirt_data *data);
void	parse_sp(char **arr, int len, char *line, t_minirt_data *data);
void	parse_cy(char **arr, int len, char *line, t_minirt_data *data);

#endif