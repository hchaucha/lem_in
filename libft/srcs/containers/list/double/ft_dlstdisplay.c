#include "libft.h"

void	ft_dlstdisplay(t_dlist *dlst)
{
	t_node	*tmp;

	if (dlst != NULL)
	{
		tmp = dlst->p_start;
		while (tmp->next)
		{
			ft_printf("%s -> ", tmp->content);
			tmp = tmp->next;
		}
	}
	ft_printf("NULL\n");
}
