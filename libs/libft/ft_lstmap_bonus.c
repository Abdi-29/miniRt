#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*lst_first;

	lst_first = NULL;
	while (lst)
	{
		lst_new = ft_lstnew((*f)(lst->content));
		if (lst_new == NULL)
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_first, lst_new);
		lst = lst->next;
	}
	return (lst_first);
}