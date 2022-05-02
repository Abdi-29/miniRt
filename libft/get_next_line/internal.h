/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   internal.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 15:42:03 by sappunn       #+#    #+#                 */
/*   Updated: 2022/04/25 15:42:03 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H
# include <wchar.h>

char		*ft_nl_substr(void *nl, char *buffer);
char		*ft_strjoin_clear(char *nl, char *str, int clear);
size_t		ft_strlen_stop(const char *str, char stop);

#endif
