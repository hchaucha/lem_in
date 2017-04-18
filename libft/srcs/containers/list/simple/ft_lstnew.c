/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaucha <hugues.chauchat@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 02:51:25 by hchaucha          #+#    #+#             */
/*   Updated: 2016/10/07 15:29:01 by hchaucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		if (content == NULL)
		{
			new->content_size = 0;
			new->content = NULL;
		}
		else
		{
			new->content_size = content_size;
			if (!ft_memalloc(new->content_size))
				return (NULL);
			new->content = ft_memcpy(new->content, content, new->content_size);
		}
		new->next = NULL;
	}
	return (new);
}
