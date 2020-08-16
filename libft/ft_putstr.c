
#include "libft.h"

int		ft_putstr(char const *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
			ft_putchar(s[i++]);
	return (i);
}
