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
