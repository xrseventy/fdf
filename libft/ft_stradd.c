
/*
**	add a new character in the end of the string
*/

#include "libft.h"

char	*ft_stradd(char *str, char ch)
{
	int		len;
	char	*new;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		if (!(new = (char*)ft_strnew(len + 1)))
			return (NULL);
		ft_strcat(new, str);
		ft_strdel(&str);
	}
	else
		new = ft_strnew(1);
	new[0] = ch;
	new[1] = '\0';
	return (new);
}
