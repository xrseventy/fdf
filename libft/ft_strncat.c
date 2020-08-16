
#include <stddef.h>

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t		i;
	char		*tmp;

	tmp = str1;
	while (*str1 != '\0' && *str1 != '\n')
		str1++;
	i = 0;
	while (i < n && str2[i])
	{
		*str1 = str2[i];
		str1++;
		i++;
	}
	*str1 = '\0';
	return (tmp);
}
