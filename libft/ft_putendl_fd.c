
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s != NULL)
	{
		while (*s != '\0')
		{
			write(fd, s, 1);
			s++;
		}
	}
	write(fd, "\n", 1);
}
