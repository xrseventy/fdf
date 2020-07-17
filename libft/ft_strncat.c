/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:29:36 by ltalitha          #+#    #+#             */
/*   Updated: 2020/07/17 17:29:39 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
