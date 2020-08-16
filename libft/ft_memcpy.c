
#include <stddef.h>

void	*ft_memcpy(void *restrict dst, void *restrict src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char*)dst)[i] = *(char*)src;
		src++;
		i++;
	}
	return (dst);
}
