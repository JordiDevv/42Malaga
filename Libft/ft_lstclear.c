#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	/*if (*lst == NULL)
		return ;*/
	node = *lst;
	while (node)
	{
		ft_lstdelone(node, del);
		node = node->next;
	}
}
