/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 15:40:50 by sappunn       #+#    #+#                 */
/*   Updated: 2022/04/25 15:40:50 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <zconf.h>

int	ft_printf(int fd, const char *str, ...);
int	ft_printf_va(int fd, const char *str, va_list ap);

#endif
