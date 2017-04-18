#ifndef DLIST_H
# define DLIST_H

typedef struct s_node
{
	void			*content;
	size_t			content_size;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct s_dlist
{
	size_t			len;
	struct s_node	*p_start;
	struct s_node	*p_end;
}			t_dlist;

t_dlist	*ft_dlstnew(void);
t_dlist	*ft_dlstpushback(t_dlist *dlst, void const *content,\
											size_t content_size);
t_dlist	*ft_dlstpushfront(t_dlist *dlst, void const *content,\
											size_t content_size);
void	ft_dlstfree(t_dlist **dlst);
void	ft_dlstdisplay(t_dlist *dlst);

#endif
