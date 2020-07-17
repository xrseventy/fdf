/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:40:01 by ltalitha          #+#    #+#             */
/*   Updated: 2020/07/17 17:40:02 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		length(char const *s)
{
	char const *p;

	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	p = s;
	while (*s != '\0')
		s++;
	if (p != s)
		s--;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s--;
	return ((s - p) + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	while ((*s == ' ' || *s == '\t' || *s == '\n') && *s)
		s++;
	str = ft_strsub(s, 0, length(s));
	return (str);
}
