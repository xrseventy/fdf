
#include "libft.h"

void	*ft_memdup(void const *src, size_t len)
{
	void	*dst;
	size_t	i;

	i = 0;
	if ((dst = malloc(len)) == NULL)
		return (NULL);
	while (i < len)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (dst);
}
