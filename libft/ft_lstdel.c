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
