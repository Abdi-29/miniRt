#ifndef PARSER_H
#define PARSER_H

typedef struct	s_parser
{
	char *option;
	void	(*t_function_pointer)(char **arr, int len, char *line, t_minirt_data *data);
}				t_parser;

void	parse_a(char **arr, int len, char *line, t_minirt_data *data);
void	parse_c(char **arr, int len, char *line, t_minirt_data *data);
void	parse_l(char **arr, int len, char *line, t_minirt_data *data);
void	parse_pl(char **arr, int len, char *line, t_minirt_data *data);
void	parse_sp(char **arr, int len, char *line, t_minirt_data *data);
void	parse_cy(char **arr, int len, char *line, t_minirt_data *data);

#endif