#include "libft.h"

t_dlist		*ft_dlstpushfront(t_dlist *dlst, void const *content,\
												size_t content_size)
{
	t_node	*new;

	if (dlst != NULL)
	{
		new = malloc(sizeof(t_node));
		if (new != NULL)
		{
			new->content_size = content_size;
			if ((new->content = malloc(new->content_size)) == NULL)
				return (NULL);
			new->content = ft_memcpy(new->content, content, new->content_size);
			if (dlst->p_end == NULL)
			{
				new->next = NULL;
				dlst->p_start = new;
				dlst->p_end = new;
			}
			else
			{
				dlst->p_start->prev = new;
				new->next = dlst->p_start;
				dlst->p_start = new;
			}
			dlst->len++;
		}
	}
	return (dlst);
}
