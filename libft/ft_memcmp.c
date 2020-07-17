/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:15:22 by ltalitha          #+#    #+#             */
/*   Updated: 2020/07/17 17:15:23 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
	{
		if (*((unsigned char*)s1) != *((unsigned char*)s2))
			return (*((unsigned char*)s1) - *((unsigned char*)s2));
		s1++;
		s2++;
	}
	return (0);
}
