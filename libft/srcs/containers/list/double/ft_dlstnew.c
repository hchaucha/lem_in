#include "libft.h"

t_dlist		*ft_dlstnew(void)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (new)
	{
		new->len = 0;
		new->p_end = NULL;
		new->p_start = NULL;
	}
	return (new);
}
