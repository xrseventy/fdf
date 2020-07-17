/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:11:35 by ltalitha          #+#    #+#             */
/*   Updated: 2020/07/17 17:11:41 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_unsigned(size_t nbr)
{
	char ch;
	char *str;

	str = NULL;
	if (nbr >= 10)
		str = ft_itoa_unsigned(nbr / 10);
	ch = nbr % 10 + '0';
	return (ft_stradd(str, ch));
}

char		*ft_itoa_long(long nbr)
{
	if (nbr < 0)
		return (ft_strjoin_free("-", ft_itoa_unsigned(-nbr), 2));
	else
		return (ft_itoa_unsigned(nbr));
}
