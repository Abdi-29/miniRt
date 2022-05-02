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

static void	parse_line(char *line, t_minirt_data *data)
{
	char	**arr;

	arr = ft_split(line, ft_iswhite_space);
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
