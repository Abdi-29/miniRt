/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   internal.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:05:10 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:05:10 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

int		print_string(char *str);
int		print_char(int c);
int		print_long(long i);
int		print_str_free(char *str);
char	*get_hex_upper(long nbr);
char	*get_hex_lower(long nbr);
char	*get_pointer(unsigned long nbr);
char	*ft_get_base(long nbr, char *characters, char *prefix);
char	*ft_get_base_ul(unsigned long nbr, char *characters, char *prefix);

#endif
