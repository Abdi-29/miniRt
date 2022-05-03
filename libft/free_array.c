/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_array.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abba <abba@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/03 16:13:38 by abba          #+#    #+#                 */
/*   Updated: 2022/05/03 16:13:38 by abba          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
