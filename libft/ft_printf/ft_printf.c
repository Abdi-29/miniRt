/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 17:59:36 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 17:59:36 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "internal.h"

/**
 * Prints the argument as a string (part 2)
 *
 * @param	str	String we're reading from
 * @param	ap	va list containing the current argument to print
 *
 * @return	amount of characters printed
 */
int	handle_character_2(int fd, const char *str, va_list ap, int err)
{
	if (*str == 'x')
		err = print_str_free(fd, get_hex_lower(va_arg(ap, unsigned int)));
	else if (*str == 'X')
		err = print_str_free(fd, get_hex_upper(va_arg(ap, unsigned int)));
	else if (*str == 'p')
		err = print_str_free(fd, get_pointer(va_arg(ap, unsigned long)));
	else if (*str == '%')
		err = ft_putchar_fd(*str, fd);
	else
	{
		err = ft_putchar_fd(*str, fd);
		err += ft_putchar_fd(*(str - 1), fd);
	}
	return (err);
}

/**
 * Prints the argument as a string
 *
 * @param	str	String we're reading from
 * @param	ap	va list containing the current argument to print
 *
 * @return	amount of characters printed
 */
int	handle_character(int fd, const char *str, va_list ap)
{
	int	len;

	len = 0;
	if (*str == 0)
		return (-2);
	if (*str == 's')
		len = print_string(fd, va_arg(ap, char *));
	else if (*str == 'c')
		len = print_char(fd, va_arg(ap, int));
	else if (*str == 'i' || *str == 'd')
		len = print_long(fd, va_arg(ap, int));
	else if (*str == 'u')
		len = print_long(fd, va_arg(ap, unsigned int));
	else
		return (handle_character_2(fd, str, ap, len));
	return (len);
}

void	handle_else(const char **str, int *total_len)
{
	ft_putchar_fd(**str, 1);
	(*str)++;
	(*total_len)++;
}

int	ft_printf_va(int fd, const char *str, va_list ap)
{
	int		len;
	int		total_len;

	len = 0;
	total_len = len;
	while (*str && len != -1)
	{
		if (*str == '%')
		{
			len = handle_character(fd, (str + 1), ap);
			if (len == -2)
				str++;
			else if (len >= 0)
			{
				total_len += len;
				str += 2;
			}
		}
		else
			handle_else(&str, &total_len);
	}
	return (total_len);
}

/**
 * Print a string to the standard output along with any specified arguments
 * 	at specified locations
 *
 * @param	str	The string to print
 * @param	...	Any arguments that are requested to be printed
 *
 * @return	amount of characters printed or negative numbers on failure
 */
int	ft_printf(int fd, const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	return (ft_printf_va(fd, str, ap));
}
