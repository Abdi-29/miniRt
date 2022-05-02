/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 17:59:41 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 17:59:41 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

void	err_exit(int status, const char *str, ...)
{
	va_list	ap;

	if (str != NULL)
	{
		va_start(ap, str);
		if (status != 0)
			ft_printf_va(2, str, ap);
		else
			ft_printf_va(1, str, ap);
	}
	exit(status);
}
