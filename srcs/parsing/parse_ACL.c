/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_ACL.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 19:22:18 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 19:22:18 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"

void	parse_a(char **arr, int len, char *line, t_minirt_data *data)
{
	if (len != 3)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
}

void	parse_c(char **arr, int len, char *line, t_minirt_data *data)
{
	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
}

void	parse_l(char **arr, int len, char *line, t_minirt_data *data)
{
	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
}
