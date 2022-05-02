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
#include "parsing.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (*arr++)
		i++;
	return (i);
}

static void	parse_line(char *line, t_minirt_data *data)
{
	char	**arr;
	int		len;

	arr = ft_split(line, ft_iswhite_space);
	if (arr == NULL)
		err_exit(1, "Error\nRan out of memory.\n");
	len = arr_len(arr);
	if (len < 3)
		err_exit(1, "Error\nNot enough arguments on the following line: [%s].\n",
			line);
	if (ft_streq(arr[0], "A"))
		parse_a(arr, len, line, data);
	else if (ft_streq(arr[0], "C"))
		parse_c(arr, len, line, data);
	else if (ft_streq(arr[0], "L"))
		parse_l(arr, len, line, data);
	else if (ft_streq(arr[0], "pl"))
		parse_pl(arr, len, line, data);
	else if (ft_streq(arr[0], "sp"))
		parse_sp(arr, len, line, data);
	else if (ft_streq(arr[0], "cy"))
		parse_cy(arr, len, line, data);
	else
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
