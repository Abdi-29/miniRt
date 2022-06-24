/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:18 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:18 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include "list/list.h"
# include "ft_printf/printf.h"
# include "get_next_line/get_next_line.h"
# include "../includes/bool.h"

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
size_t	ft_strlen(const char *c);
char	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str, t_bool *success);
double	ft_atod(const char *str, t_bool *success);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
int		ft_streq(const char *s1, const char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, int (*func)(char));
char	*ft_itoa(long n);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long n, int fd);
int		ft_iswhite_space(char c);
int		ft_ends_with(char *str, char *suffix);
void	free_array(char **array);

#endif
