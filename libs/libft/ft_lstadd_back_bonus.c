#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!tmp)
		return ;
	while (tmp)
	{
		if ((tmp)->next == NULL)
		{
			tmp->next = new;
			break ;
		}
		else
			tmp = tmp->next;
	}
}
