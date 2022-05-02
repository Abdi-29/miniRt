/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sappunn <sappunn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/10 18:11:02 by sappunn       #+#    #+#                 */
/*   Updated: 2021/12/10 18:11:02 by sappunn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * Iterate over a string and apply the function f to its content
 *
 * @param	s	String to iterate over
 * @param	f	Function to apply to string
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	while (*(s + i))
	{
		f(i, (s + i));
		i++;
	}
}
