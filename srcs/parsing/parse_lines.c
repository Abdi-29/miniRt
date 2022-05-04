/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_lines.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 18:38:36 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 18:38:36 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"
#include "../../includes/parser.h"

static void	parse_line(char *line, t_minirt_data *data)
{
	char			**arr;
	int				len;
	int				i;
	const t_parser	function[] = {
	{"A", &parse_a}, {"C", &parse_c},
	{"L", &parse_l}, {"pl", &parse_pl},
	{"sp", &parse_sp}, {"cy", &parse_cy}
	};

	i = 0;
	arr = ft_split(line, ft_iswhite_space);
	if (arr == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	len = arr_len((const char **)arr);
	if (len < 3)
		err_exit(1, "Error\nNot enough arguments on the following line: [%s].\n",
			line);
	while (function[i].option)
	{
		if (ft_streq(arr[0], function[i].option))
			return (function[i].t_function_pointer(arr, len, line, data));
		i++;
	}
	err_exit(1, "Error\nInvalid identifier [%s] on line [%s].\n",
		arr[0], line);
}

void	parse_lines(t_list **head, t_minirt_data *data)
{
	t_list	*entry;

	entry = *head;
	while (entry)
	{
		parse_line(entry->content, data);
		entry = entry->next;
	}
}
