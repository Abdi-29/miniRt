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

int	arr_len(char *line)
{
	int	i;

	i = 0;
	while (*line++)
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
	len = arr_len(line);
	if (len < 3)
		err_exit(1, "Error\nNot enough arguments on the following line: [%s]\n", line);
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
