/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 17:17:42 by abba          #+#    #+#                 */
/*   Updated: 2022/06/20 17:17:42 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

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
