/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinograd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 11:18:15 by vinograd          #+#    #+#             */
/*   Updated: 2020/03/04 18:26:50 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *lnext;

	if (alst != NULL)
	{
		tmp = *alst;
		lnext = *alst;
		while (tmp != NULL)
		{
			(*del)(tmp->content, tmp->content_size);
			tmp = lnext->next;
			free(lnext);
			lnext = tmp;
		}
		*alst = NULL;
	}
}
