/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   len_array.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:12:31 by abba          #+#    #+#                 */
/*   Updated: 2022/05/03 16:12:31 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	len_array(char **array)
{
	int	len;

	len = 0;
	while (array[len++])
		;
	return (len);
}