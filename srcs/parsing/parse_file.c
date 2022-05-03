/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:15:02 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 15:15:02 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"
#include "../../includes/parser.h"

#include <fcntl.h>

static t_bool	empty_line(char *line)
{
	while (ft_iswhite_space(*line))
		line++;
	if (*line == 0 || *line == '\n')
		return (true);
	return (false);
}

static void	load_file(int fd, t_list **head)
{
	char	*line;
	t_list	*new;

	line = get_next_line(fd);
	while (line)
	{
		line[ft_strlen(line)] = 0;
		if (empty_line(line) == true)
			free(line);
		else
		{
			new = ft_lstnew(line);
			if (new == NULL)
				err_exit(1, "Error\nRan out of memory.\n");
			ft_lstadd_back(head, new);
		}
		line = get_next_line(fd);
	}
}

void free_list(t_list **head)
{
	t_list	*tmp;
	t_list	*current;

	current	= *head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

void	parse_file(char *file, t_minirt_data *data)
{
	int		fd;
	t_list	**head;

	if (!ft_ends_with(file, ".rt"))
		err_exit(1, "Error\nInvalid file name: [%s], needs to be a .rt file\n",
			file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		err_exit(1, "Error\nUnable to open file: [%s]\n", file);
	head = ft_calloc(1, sizeof(t_list *));
	if (!head)
		return ;
	load_file(fd, head);
	parse_lines(head, data);
	free_list(head);
}
