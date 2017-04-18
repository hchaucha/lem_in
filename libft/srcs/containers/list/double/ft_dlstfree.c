#include "libft.h"

void	ft_dlstfree(t_dlist **dlst)
{
	t_node	*tmp;
	t_node	*del;
	if (*dlst != NULL)
	{
		tmp = (*dlst)->p_start;
		while (tmp != NULL)
		{
			del = tmp;
			tmp = tmp->next;
			free(del);
		}
		free(*dlst);
		dlst = NULL;
	}
}
