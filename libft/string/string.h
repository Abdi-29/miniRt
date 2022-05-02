/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 15:32:31 by sappunn       #+#    #+#                 */
/*   Updated: 2022/02/28 15:32:31 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H
# include "../../includes/bool.h"

typedef struct s_string
{
	char	*s;
	int		len;
	int		empty;
}	t_string;

t_bool		ft_str_eq(t_string *s1, t_string *s2);
t_string	*join_strings(t_string *s1, t_string *s2);
t_string	*append_char_array(t_string *s, char *arr);
t_string	*dup_string(t_string *s);
t_string	*init_string(char *arr);
void		free_string(t_string *s);
t_string	*append_char(t_string *s, char c);
#endif
