/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:10:38 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:10:38 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/**
 * Calculates the size of the given t_list
 *
 * @param	lst	The start of the t_list to get the size of
 *
 * @return	The size of the given t_list as an integer
 */
int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while ((lst->next))
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
