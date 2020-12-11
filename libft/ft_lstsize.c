#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int lstsize;

	lstsize = 0;
	while (lst)
	{
		lstsize++;
		lst = lst->next;
	}
	return (lstsize);
}
