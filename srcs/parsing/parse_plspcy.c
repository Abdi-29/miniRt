/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_plspcy.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/02 19:22:15 by sappunn       #+#    #+#                 */
/*   Updated: 2022/05/02 19:22:15 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lib.h"
#include "../../includes/data_struct.h"
#include "../../includes/util.h"

void	parse_pl(char **arr, int len, char *line, t_minirt_data *data)
{
	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
}

void	parse_sp(char **arr, int len, char *line, t_minirt_data *data)
{
	if (len != 4)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
}

void	parse_cy(char **arr, int len, char *line, t_minirt_data *data)
{
	if (len != 6)
		err_exit(1, "Error\nInvalid argument length [%d] on line [%s].\n",
			len, line);
}