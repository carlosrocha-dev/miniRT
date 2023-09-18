#include "../libft.h"

void	ft_dlstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	ft_lstdelone(lst->prev, del);
	ft_lstdelone(lst->next, del);
	del(lst->content);
	free(lst);
}
