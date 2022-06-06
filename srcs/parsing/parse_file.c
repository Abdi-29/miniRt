/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_file.c                                        :+:    :+:           */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 15:15:02 by sappunn       #+#    #+#                 */
/*   Updated: 2022/06/06 11:02:10 by abba            ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"

#include <fcntl.h>

static t_bool	empty_line(char *line)
{
	int	i;

	i = 0;
	while (ft_iswhite_space(line[i]))
		i++;
	if (line[i] == 0)
		return (TRUE);
	return (FALSE);
}
#include <stdio.h>
static void	load_file(int fd, t_list **head)
{
	char	*line;
	t_list	*new;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free (line);
			break ;
		}
		if (ft_strlen(line) > 1 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		if (empty_line(line) == TRUE)
			free(line);
		else
		{
			new = ft_lstnew(ft_strdup(line));
			free(line);
			line = NULL;
			if (new == NULL)
				err_exit(1, "Error\nRan out of memory.\n");
			ft_lstadd_back(head, new);
		}
	}
}
/*
void	free_list(t_list **head)
{
	t_list	*current;

	while (*head)
	{
		current = (*head)->next;
		free((*head)->content);
		free((*head));
		*head = current;
	}
}
*/
void	parse_file(char *file, t_minirt_data *data)
{
	int		fd;
	t_list	*head;

	head = NULL;
	if (!ft_ends_with(file, ".rt"))
		err_exit(1, "Error\nInvalid file name: [%s], needs to be a .rt file\n",
			file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		err_exit(1, "Error\nUnable to open file: [%s]\n", file);
	load_file(fd, &head);
	parse_lines(&head, data);
	free_list(&head);
	close(fd);
}
