/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:36 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:36 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

/**
 * Iterates through a given t_list to execute a given function
 * 	on each entries content and store the result of that entry
 * 	in a new t_list
 *
 * @param	lst	The t_list to iterate through
 * @param	f	The function to apply to each t_list's content
 * @param	del	The function to apply to the t_list content to clear
 * 	it's content if needed
 *
 * @return	A new t_list that contains a version of the t_list that had
 * the function f applied to all of it's entries content
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_element;
	t_list	*tmp;
	t_list	*start;

	if (!lst)
		return (NULL);
	tmp = lst;
	start = ft_lstnew(f(tmp->content));
	if (!start)
		return (NULL);
	tmp = tmp->next;
	while (tmp)
	{
		new_element = ft_lstnew(f(tmp->content));
		if (new_element == 0)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new_element);
		tmp = tmp->next;
	}
	return (start);
}
