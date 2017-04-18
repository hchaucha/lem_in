#include "libft.h"

t_dlist		*ft_dlstpushback(t_dlist *dlst, void const *content,\
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
			new->next = NULL;
			if (dlst->p_end == NULL)
			{
				new->prev = NULL;
				dlst->p_end = new;
				dlst->p_start = new;
			}
			else
			{
				dlst->p_end->next = new;
				new->prev = dlst->p_end;
				dlst->p_end = new;
			}
			dlst->len++;
		}
	}
	return (dlst);
}
