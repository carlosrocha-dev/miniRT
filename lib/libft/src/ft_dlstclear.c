#include "../libft.h"

void ft_dlstclear(t_list **lst)
{
	t_list *current;
	t_list *next;

	if (lst == NULL || *lst == NULL)
		return;

	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*lst = NULL;
}
