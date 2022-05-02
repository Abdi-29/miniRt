/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrepl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:14 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:14 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrepl(char *str, char *find, char *replace)
{
	char	*tmp;
	char	*new;
	int		find_len;
	int		repl_len;

	find_len = ft_strlen(find);
	repl_len = ft_strlen(replace);
	tmp = ft_strnstr(str, find, ft_strlen(str));
	if (tmp == NULL)
		return (str);
	new = ft_calloc(ft_strlen(str) - find_len + repl_len + 1, sizeof(char));
	ft_memcpy(new, str, tmp - str);
	ft_memcpy(new + ft_strlen(new), replace, repl_len);
	ft_memcpy(new + ft_strlen(new), (void *)(tmp + find_len), ft_strlen(tmp));
	return (new);
}
