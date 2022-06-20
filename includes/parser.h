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

typedef struct s_element
{
	char		**coords;
	char		**vector;
	char		**rgb;
}				t_element;

void	parse_file(char *file, t_minirt_data *data);
void	parse_lines(t_list **head, t_minirt_data *data);
void	parse_ambient(char **arr, int len, char *line, t_minirt_data *data);
void	parse_camera(char **arr, int len, char *line, t_minirt_data *data);
void	parse_light(char **arr, int len, char *line, t_minirt_data *data);
void	parse_plane(char **arr, int len, char *line, t_minirt_data *data);
void	parse_sphere(char **arr, int len, char *line, t_minirt_data *data);
void	parse_cylinder(char **arr, int len, char *line, t_minirt_data *data);

#endif