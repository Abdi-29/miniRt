#include "libft.h"
#include <stdlib.h>

void	last(void)
{
	system("leaks get_next_line");
}

int	main(void)
{
	char	*new;
	new = ft_strrepl("test <kk> test", "<kk>", "something else");
	ft_printf(new);
	free(new);
	return (0);
}
