#include "libft.h"

void		list_cpy(t_list **src, t_list *cpy)
{
	(*src)->content = cpy->content;
}

int			sort_alpha(t_list *lst1, t_list *lst2)
{
	return (ft_strcmp(lst1->content, lst2->content));
}

void		sort_swap(t_list **a, t_list **b)
{
	t_list	tmp;

	tmp = **a;
	list_cpy(a, *b);
	list_cpy(b, &tmp);
}

void		sort(t_list **list, int (*cmp)(t_list *lst1, t_list *lst2))
{
	t_list	*a;
	t_list	*b;

	a = *list;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (cmp(a, b) > 0)
				sort_swap(&a, &b);
			b = b->next;
		}
		a = a->next;
	}
}

t_list		*ft_lstsort(t_list *lst)
{
	t_list	*new;

	new = lst;
	sort(&lst, sort_alpha);
	return (new);
}
